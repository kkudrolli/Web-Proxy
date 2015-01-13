/*
 * test_cache.c
 *
 * Author: Kais Kudrolli
 * Andrew ID: kkudroll
 *
 * File Description: This file tests basic cache functions.
 */

#include <assert.h>

#include "cache.h"

int main() {
    
    Cache *cache = NULL;
    char uri[MAX_OBJECT_SIZE];
    char uri2[MAX_OBJECT_SIZE];
    char uri3[MAX_OBJECT_SIZE];
    char content[MAX_OBJECT_SIZE];
    char object[MAX_OBJECT_SIZE];
    char object2[MAX_OBJECT_SIZE];
    char object3[MAX_OBJECT_SIZE];
    strcpy(uri, "A");
    strcpy(content, "Bye ");
    int hit;

    cache = cache_init(cache);

    assert(cache != NULL);

    /* Starting size of the cache is 0 */
    assert(get_cache_size(cache) == 0);

    /* Lookup without adding anything should yield a miss */
    assert(!cache_lookup(cache, uri, object));

    /* After adding a node, there should be a hit */
    cache_add(cache, uri, content);
    hit = cache_lookup(cache, uri, object);
    assert(hit);
    assert(!strcmp(content, object));

    /* Add nodes so that one has to be removed */
    /* Changed macros in cache.h to be lower when testing */
    /* object -> 4, cache -> 10 */
    strcpy(uri2, "B");
    strcpy(object2, "hi! ");
    strcpy(uri3, "C");
    strcpy(object3, "bye ");
    cache_add(cache, uri2, object2);
    cache_add(cache, uri3, object3);
    hit = cache_lookup(cache, uri3, content);
    assert(hit);
    assert(!strcmp(content, object3));
    hit = cache_lookup(cache, uri, content);
    assert(!hit);
    assert(strcmp(content, object));

    cache_destroy(cache);
    printf("Passed all tests!\n");
    return 0;
}

