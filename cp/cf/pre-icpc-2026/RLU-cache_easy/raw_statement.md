RLU cache is a cache where the least recently used item will be discard if there is no space for new data to be added in

Initially the cache has value = 0, with size of N
There will be q queries (q <= 2e5)
Type 1: add a, b, insert a to the RLU cache
Type 2: query a, find the value of a in the RLU cache and its order in the RLU cache, if the value has been invalidated, return -1
