/**
 *
 * http://www.cprogramming.com/tutorial/computersciencetheory/hash-table.html
 * https://www.tutorialspoint.com/data_structures_algorithms/hash_table_program_in_c.htm
 * https://gist.github.com/tonious/1377667
 */


#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__


#define HASH_TABLE_SIZE 20

typedef struct _hash_table_key_value {
    int key;
    char *data;
} hash_table_key_value_t;


int
hash_table_hash(const int key)
{
    return 1;
}


hash_table_key_value_t *
hash_table_insert(hash_table_key_value_t *hash_table, int key, char *data)
{
    hash_table_key_value_t *item;
    item = malloc(sizeof(hash_table_key_value_t));

    item->key = key;
    item->data = data;

    int hashed_key = hash_table_hash(key);

    return item;
}


void
hash_table_remove()
{

}


void
hash_table_get()
{

}


void
hash_table_set()
{

}


void
hash_table_print()
{

}


void
test_hash_table()
{
    hash_table_key_value_t hash_table[HASH_TABLE_SIZE];
    // hash_table_key_value_t *item;

    hash_table_insert(hash_table, 1, "first");

}


#endif // __HASH_TABLE_H__
