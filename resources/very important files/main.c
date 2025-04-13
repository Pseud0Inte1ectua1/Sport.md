
    if (vector->m_data == NULL)
        return -1;
    return 0;
}

FT_INTERNAL
size_t vector_capacity(const f_vector_t *vector)
{
    assert(vector);
    return vector->m_capacity;
}


FT_INTERNAL
int vector_push(f_vector_t *vector, const void *item)
{
    assert(vector);
    assert(item);

    if (vector->m_size == vector->m_capacity) {
        if (vector_reallocate_(vector, vector->m_capacity * 2) == -1)
            return FT_GEN_ERROR;
        vector->m_capacity = vector->m_capacity * 2;
    }

    size_t offset = vector->m_size * vector->m_item_size;
    memcpy((char *)vector->m_data + offset, item, vector->m_item_size);

    ++(vector->m_size);

    return FT_SUCCESS;
}

FT_INTERNAL
int vector_insert(f_vector_t *vector, const void *item, size_t pos)
{
    assert(vector);
    assert(item);
    size_t needed_capacity = MAX(pos + 1, vector->m_size + 1);
    if (vector->m_capacity < needed_capacity) {
        if (vector_reallocate_(vector, needed_capacity) == -1)
            return FT_GEN_ERROR;
        vector->m_capacity = needed_capacity;
    }
    size_t offset = pos * vector->m_item_size;
    if (pos >= vector->m_size) {
        /* Data in the middle are not initialized */
        memcpy((char *)vector->m_data + offset, item, vector->m_item_size);
        vector->m_size = pos + 1;
        return FT_SUCCESS;
    } else {
        /* Shift following data by one position */
        memmove((char *)vector->m_data + offset + vector->m_item_size,
                (char *)vector->m_data + offset,
                vector->m_item_size * (vector->m_size - pos));
        memcpy((char *)vector->m_data + offset, item, vector->m_item_size);
        ++(vector->m_size);
        return FT_SUCCESS;
    }
}

FT_INTERNAL
f_vector_t *vector_split(f_vector_t *vector, size_t pos)
{
    size_t trailing_sz = vector->m_size > pos ? vector->m_size - pos : 0;
    f_vector_t *new_vector = create_vector(vector->m_item_size, trailing_sz);
    if (!new_vector)
        return new_vector;
    if (new_vector->m_capacity < trailing_sz) {
        destroy_vector(new_vector);
        return NULL;
    }

    if (trailing_sz == 0)
        return new_vector;

    size_t offset = vector->m_item_size * pos;
    memcpy(new_vector->m_data, (char *)vector->m_data + offset,
           trailing_sz * vector->m_item_size);
    new_vector->m_size = trailing_sz;
    vector->m_size = pos;
    return new_vector;
}

FT_INTERNAL
const void *vector_at_c(const f_vector_t *vector, size_t index)
{
    if (index >= vector->m_size)
        return NULL;

    return (char *)vector->m_data + index * vector->m_item_size;
vector->m_item_size;
}

FT_INTERNAL
f_status vector_swap(f_vector_t *cur_vec, f_vector_t *mv_vec, size_t pos)
{
    assert(cur_vec);
    assert(mv_vec);
    assert(cur_vec != mv_vec);
    assert(cur_vec->m_item_size == mv_vec->m_item_size);


        return NULL;

    f_vector_t *new_vector = create_vector(v->m_item_size, v->m_capacity);
    if (new_vector == NULL)
        return NULL;

    memcpy(new_vector->m_data, v->m_data, v->m_item_size * v->m_size);
#endif
