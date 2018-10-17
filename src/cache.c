#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "cache.h"

/**
 * Allocate a cache entry
 */
struct cache_entry *alloc_entry(char *path, char *content_type, void *content, int content_length)
{
    struct cache_entry *ce = malloc(sizeof(ce));

    ce->path = malloc(strlen(path)); //memory for string
    strcpy(ce->path, path);          //copy string

    ce->content_type = malloc(strlen(content_type));
    strcpy(ce->content_type, content_type);

    ce->content = malloc(strlen(content_length));
    memcpy(ce->content, content, content_length);

    ce->content_length = content_length;
}

/**
 * Deallocate a cache entry
 */
void free_entry(struct cache_entry *v_ent)
{ //removed void *varg param
    free(v_ent->content);
    free(v_ent->content_type);
    free(v_ent->path);
    free(v_ent);
}

/**
 * Insert a cache entry at the head of the linked list
 */
void dllist_insert_head(struct cache *cache, struct cache_entry *ce)
{
    // Insert at the head of the list
    if (cache->head == NULL)
    {
        cache->head = cache->tail = ce;
        ce->prev = ce->next = NULL;
    }
    else
    {
        cache->head->prev = ce;
        ce->next = cache->head;
        ce->prev = NULL;
        cache->head = ce;
    }
}

/**
 * Move a cache entry to the head of the list
 */
void dllist_move_to_head(struct cache *cache, struct cache_entry *ce)
{
    if (ce != cache->head)
    {
        if (ce == cache->tail)
        {
            // We're the tail
            cache->tail = ce->prev;
            cache->tail->next = NULL;
        }
        else
        {
            // We're neither the head nor the tail
            ce->prev->next = ce->next;
            ce->next->prev = ce->prev;
        }

        ce->next = cache->head;
        cache->head->prev = ce;
        ce->prev = NULL;
        cache->head = ce;
    }
}

/**
 * Removes the tail from the list and returns it
 * 
 * NOTE: does not deallocate the tail
 */
struct cache_entry *dllist_remove_tail(struct cache *cache)
{
    struct cache_entry *oldtail = cache->tail;

    cache->tail = oldtail->prev;
    cache->tail->next = NULL;

    cache->cur_size--;

    return oldtail;
}

/**
 * Create a new cache
 * 
 * max_size: maximum number of entries in the cache
 * hashsize: hashtable size (0 for default)
 */
struct cache *cache_create(int max_size, int hashsize)
{
    ///////////////////
    // IMPLEMENT ME! //
    ///////////////////
}

/**
 * Store an entry in the cache
 *
 * This will also remove the least-recently-used items as necessary.
 * 
 * NOTE: doesn't check for duplicate cache entries
 */
void cache_put(struct cache *cache, char *path, char *content_type, void *content, int content_length)
{
    ///////////////////
    // IMPLEMENT ME! //
    ///////////////////

    //   -  Allocate a new cache entry with the passed parameters.
    //   -  Insert the entry at the head of the doubly-linked list.
    //      insert_head function
    //   -  Store the entry in the hashtable as well, indexed by the entry's path.
    //   -  Increment the current size of the cache.
    //   -  If the cache size is greater than the max size:
    //   -  Remove the entry from the hashtable, using the entry's path and the hashtable_delete function.
    //   -  Remove the cache entry at the tail of the linked list.
    //   -  Free the cache entry.
    //   -  Ensure the size counter for the number of entries in the cache is correct.
}

/**
 * Retrieve an entry from the cache
 */
struct cache_entry *cache_get(struct cache *cache, char *path)
{
    ///////////////////
    // IMPLEMENT ME! //
    ///////////////////
    // - Attempt to find the cache entry pointer by path in the hash table. hashtable_get( ,path)
    // -  If not found, return NULL. print error
    // 1- Move the cache entry to the head of the doubly - linked list.
    // 2- Return the cache entry pointer.
}
