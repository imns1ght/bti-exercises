#ifndef CLIENTF_H
#define CLIENTF_H

// Useful alias
using byte = unsigned char;
using Compare = bool (*)(const void *, const void *);
using Predicate = bool (*)(const void *);
using Equal = bool (*)(const void *, const void *);

/// The comparison function (strict total order)
bool cmp(const void *a, const void *b);

#endif

