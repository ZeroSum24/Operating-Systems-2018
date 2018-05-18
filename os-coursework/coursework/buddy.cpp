/*
 * Buddy Page Allocation Algorithm
 * SKELETON IMPLEMENTATION -- TO BE FILLED IN FOR TASK (2)
 */

/*
 * STUDENT NUMBER: s
 */
#include <infos/mm/page-allocator.h>
#include <infos/mm/mm.h>
#include <infos/kernel/kernel.h>
#include <infos/kernel/log.h>
#include <infos/util/math.h>
#include <infos/util/printf.h>

using namespace infos::kernel;
using namespace infos::mm;
using namespace infos::util;

#define MAX_ORDER    17

/**
 * A buddy page allocation algorithm.
 */
class BuddyPageAllocator : public PageAllocatorAlgorithm {
private:
    /**
     * Returns the number of pages that comprise a 'block', in a given order.
     * @param order The order to base the calculation off of.
     * @return Returns the number of pages in a block, in the order.
     */
    static inline constexpr uint64_t pages_per_block(int order) {
        /* The number of pages per block in a given order is simply 1, shifted left by the order number.
         * For example, in order-2, there are (1 << 2) == 4 pages in each block.
         */
        return (1 << order);
    }

    /**
     * Returns TRUE if the supplied page descriptor is correctly aligned for the
     * given order.  Returns FALSE otherwise.
     * @param pgd The page descriptor to test alignment for.
     * @param order The order to use for calculations.
     */
    static inline bool is_correct_alignment_for_order(const PageDescriptor *pgd, int order) {
        // Calculate the page-frame-number for the page descriptor, and return TRUE if
        // it divides evenly into the number pages in a block of the given order.
        return (sys.mm().pgalloc().pgd_to_pfn(pgd) % pages_per_block(order)) == 0;
    }

    /** Given a page descriptor, and an order, returns the buddy PGD.  The buddy could either be
     * to the left or the right of PGD, in the given order.
     * @param pgd The page descriptor to find the buddy for.
     * @param order The order in which the page descriptor lives.
     * @return Returns the buddy of the given page descriptor, in the given order.
     */
    PageDescriptor *buddy_of(PageDescriptor *pgd, int order) {
        // (1) Make sure 'order' is within range
        if (order >= MAX_ORDER) {
            return NULL;
        }

        // (2) Check to make sure that PGD is correctly aligned in the order
        if (!is_correct_alignment_for_order(pgd, order)) {
            return NULL;
        }

        // (3) Calculate the page-frame-number of the buddy of this page.
        // * If the PFN is aligned to the next order, then the buddy is the next block in THIS order.
        // * If it's not aligned, then the buddy must be the previous block in THIS order.
        uint64_t buddy_pfn = is_correct_alignment_for_order(pgd, order + 1) ?
                             sys.mm().pgalloc().pgd_to_pfn(pgd) + pages_per_block(order) :
                             sys.mm().pgalloc().pgd_to_pfn(pgd) - pages_per_block(order);

        // (4) Return the page descriptor associated with the buddy page-frame-number.
        return sys.mm().pgalloc().pfn_to_pgd(buddy_pfn);
    }

    /**
     * Inserts a block into the free list of the given order.  The block is inserted in ascending order.
     * @param pgd The page descriptor of the block to insert.
     * @param order The order in which to insert the block.
     * @return Returns the slot (i.e. a pointer to the pointer that points to the block) that the block
     * was inserted into.
     */
    PageDescriptor **insert_block(PageDescriptor *pgd, int order) {
        // Starting from the _free_area array, find the slot in which the page descriptor
        // should be inserted.
        PageDescriptor **slot = &_free_areas[order];

        // Iterate whilst there is a slot, and whilst the page descriptor pointer is numerically
        // greater than what the slot is pointing to.
        while (*slot && pgd > *slot) {
            slot = &(*slot)->next_free;
        }

        // Insert the page descriptor into the linked list.
        pgd->next_free = *slot;
        *slot = pgd;

        // Return the insert point (i.e. slot)
        return slot;
    }

    /**
     * Removes a block from the free list of the given order.  The block MUST be present in the free-list, otherwise
     * the system will panic.
     * @param pgd The page descriptor of the block to remove.
     * @param order The order in which to remove the block from.
     */
    void remove_block(PageDescriptor *pgd, int order) {
        // Starting from the _free_area array, iterate until the block has been located in the linked-list.
        PageDescriptor **slot = &_free_areas[order];
        while (*slot && pgd != *slot) {
            slot = &(*slot)->next_free;
        }

        // Make sure the block actually exists.  Panic the system if it does not.
        assert(*slot == pgd);

        // Remove the block from the free list.
        *slot = pgd->next_free;
        pgd->next_free = NULL;
    }

    /**
     * Given a pointer to a block of free memory in the order "source_order", this function will
     * split the block in half, and insert it into the order below.
     * @param block_pointer A pointer to a pointer containing the beginning of a block of free memory.
     * @param source_order The order in which the block of free memory exists.  Naturally,
     * the split will insert the two new blocks into the order below.
     * @return Returns the left-hand-side of the new block.
     */
    PageDescriptor *split_block(PageDescriptor **block_pointer, int source_order) {
        // Make sure there is an incoming pointer.
        assert(*block_pointer);

        // Make sure the block_pointer is correctly aligned.
        assert(is_correct_alignment_for_order(*block_pointer, source_order));

        // TODO: Implement this function

        //TODO: add error checking in here

        int new_order = source_order - 1;

        //split the block into two blocks
        PageDescriptor *first = *block_pointer;
        PageDescriptor *second = first + amount_of_block_pages;

        uint64_t amount_of_block_pages = pages_per_block(new_order);

        //remove the initial block
        remove_block(block_pointer, source_order);
        //insert both blocks into the an order less than the split_block
        insert_block(first, new_order);
        insert_block(second, new_order);

        return first;
    }

    /**
     * Takes a block in the given source order, and merges it (and it's buddy) into the next order.
     * This function assumes both the source block and the buddy block are in the free list for the
     * source order.  If they aren't this function will panic the system.
     * @param block_pointer A pointer to a pointer containing a block in the pair to merge.
     * @param source_order The order in which the pair of blocks live.
     * @return Returns the new slot that points to the merged block.
     */
    PageDescriptor **merge_block(PageDescriptor **block_pointer, int source_order) {
        assert(*block_pointer);

        // Make sure the area_pointer is correctly aligned.
        assert(is_correct_alignment_for_order(*block_pointer, source_order));

        // TODO: Implement this function

        // TODO add an error check in (especially around the free list assumption)
        int new_order = source_order + 1;

        //Get block one and two in the same order
        PageDescriptor *first = *block_pointer;
        PageDescriptor *second = buddy_of(first, source_order);

        //Remove the old blocks: first and second
        remove_block(first, source_order);
        remove_block(second, source_order);

        //Insert the new block in the new order according to which buddy was called
        if (first > second) {
            insert_block(second, new_order);
        } else {
            insert_block(first, new_order);
        }

    }

public:
    /**
     * Constructs a new instance of the Buddy Page Allocator.
     */
    BuddyPageAllocator() {
        // Iterate over each free area, and clear it.
        for (unsigned int i = 0; i < ARRAY_SIZE(_free_areas); i++) {
            _free_areas[i] = NULL;
        }
    }

    /**
     * Allocates 2^order number of contiguous pages
     * @param order The power of two, of the number of contiguous pages to allocate.
     * @return Returns a pointer to the first page descriptor for the newly allocated page range, or NULL if
     * allocation failed.
     */
    PageDescriptor *alloc_pages(int order) override {

        //Need to find the highest order above the given one that is not empty
        int ord = order++;
        while (NULL == free_areas[ord]) {
            if (ord >= MAX_ORDER) {
                return NULL;
            }
            ord++;
        }

        PageDescriptor *pgd = _free_areas[o];

        //Need to repeatedly split blocks until target order is reached
        for (int i = ord; i > order; i--) {
            pgd = split_block(&pgd, i);
        }
        //TODO add more error checking
        remove_block(pgd, order);

        return pgd;
    }

    /**
     * Frees 2^order contiguous pages.
     * @param pgd A pointer to an array of page descriptors to be freed.
     * @param order The power of two number of contiguous pages to free.
     */
    void free_pages(PageDescriptor *pgd, int order) override {
        // Make sure that the incoming page descriptor is correctly aligned
        // for the order on which it is being freed, for example, it is
        // illegal to free page 1 in order-1.
        assert(is_correct_alignment_for_order(pgd, order));


        PageDescriptor **added_block = insert_block(pgd, order);
        PageDescriptor *buddy_potential = _free_areas[order];
        PageDescriptor *buddy_of = buddy_of(*added_block, order);


        //Need to look at the neighbouring block (buddy) to see if it is free too
        for (int i = order; i < MAX_ORDER; i++) {
            if (buddy_potential) {
                //Stop if a non-free neighbour block is encountered in buddy_potential
                break;
            } else if (buddy_of == buddy_potential) {
                //If the neighbouring block is free too, combine the two
                added_block = merge_block(added_block, i);
                buddy_potential = _free_areas[i];
                buddy_of = buddy_of(*added_block, i);
            } else {
                //Otherwise move onto the next block in the current order
                buddy_potential = buddy_potential->next_free;
                i--;
            }
        }
    }


    /**
     * Reserves a specific page, so that it cannot be allocated.
     * @param pgd The page descriptor of the page to reserve.
     * @return Returns TRUE if the reservation was successful, FALSE otherwise.
     */
    bool reserve_page(PageDescriptor *pgd) {

        int pdg_found = false;
        PageDescriptor *current_block, *pdg_in_block;

        //Loops through the each order to check if the page is in that order
        for (int i = 0; i < MAX_ORDER; i++) {
            if (!pdg_found) {
                //If the page hasn't been found it sets the current block to the next free area in the order
                current_block = _free_areas[i];

                while (current_block) {
                    if (((pdg < (pages_per_block(i) + current_block)) && (pdg >= current_block))) {

                        pdg_in_block = current_block;

                        //If the page is in the current block it split the block to find the page to be reserved
                        while ( i > 0 ) {
                            block_w_pgd = split_block(&block_w_pgd, i);
                            i--;
                            if (!((pdg < (pages_per_block(order) + current_block)) && (pdg >= current_block))) {
                                //It checks that the page is in the current block otherwise it swaps to the buddy to split
                                pdg_in_block = buddy_of(block_w_pgd, order);
                            }
                        }
                        pdg_found = true;
                        assert(is_correct_alignment_for_order(block_w_pgd, 0));
                        assert(pdg_in_block == pgd);
                        break;
                    } else {
                        //If the page is not in the current block it sets the current_block to the next free and the loop continues
                        current_block = current_block->next_free;
                    }
                }
            } else {
                //If the page is found the loop breaks for efficiency
                break;
            }
        }

        remove_block(pgd, 0);

        return pdg_found;


    }

    /**
     * Initialises the allocation algorithm.
     * @return Returns TRUE if the algorithm was successfully initialised, FALSE otherwise.
     */
    bool init(PageDescriptor *page_descriptors, uint64_t nr_page_descriptors) override {
        // mm_log.messagef(LogLevel::DEBUG, "Buddy Allocator Initialising pd=%p, nr=0x%lx", page_descriptors, nr_page_descriptors);

        // TODO: Initialise the free area linked list for the maximum order
        // to initialise the allocation algorithm.

        PageDescriptor *pgd;
        int remaining_pdgs = nr_page_descriptors;
        uint64_t indx_for_pdg = 0;
        int order = MAX_ORDER - 1;
        int blocks;
        int remaining_blocks;

        //Loop until finished with blocks divided for each order
        while ((remaining_pdgs > 0) && (order >= 0) && (indx_for_pdg < nr_page_descriptors)) {

            remaining_blocks = remaining_pdgs % pages_per_block(order);
            blocks = remaining_pdgs / pages_per_block(order);

            //Set the pointer to the first free page in the order and then for each set linked lists
            if (blocks > 0) {
                _free_areas[order] = &page_descriptors[indx_for_pdg];
                pgd = _free_areas[order];

                for (int i = 1; i < blocks; i++) {
                    indx_for_pdg += pages_per_block(order);
                    pgd->next_free = &page_descriptors[indx_for_pdg];
                    pgd = pgd->next_free;
                }

            }

        }
        return true;
    }

/**
 * Returns the friendly name of the allocation algorithm, for debugging and selection purposes.
 */
    const char *name() const override { return "buddy"; }

/**
 * Dumps out the current state of the buddy system
 */
    void dump_state()

    const override {
// Print out a header, so we can find the output in the logs.
        mm_log.
                messagef(LogLevel::DEBUG,
                         "BUDDY STATE:");

// Iterate over each free area.
        for (
                unsigned int i = 0;
                i < ARRAY_SIZE(_free_areas);
                i++) {
            char buffer[256];
            snprintf(buffer,
                     sizeof(buffer), "[%d] ", i);

// Iterate over each block in the free area.
            PageDescriptor *pg = _free_areas[i];
            while (pg) {
// Append the PFN of the free block to the output buffer.
                snprintf(buffer,
                         sizeof(buffer), "%s%lx ", buffer, sys.

                                        mm()

                                 .

                                         pgalloc()

                                 .
                                         pgd_to_pfn(pg)
                );
                pg = pg->next_free;
            }

            mm_log.
                    messagef(LogLevel::DEBUG,
                             "%s", buffer);
        }
    }


private:
    PageDescriptor *_free_areas[MAX_ORDER];
};

/* --- DO NOT CHANGE ANYTHING BELOW THIS LINE --- */

/*
 * Allocation algorithm registration framework
 */
RegisterPageAllocator(BuddyPageAllocator);
