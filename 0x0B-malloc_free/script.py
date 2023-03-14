import os

names = [
    "main.h",
    "0-create_array.c",
    "1-strdup.c",
    "2-str_concat.c",
    "3-alloc_grid.c",
    "4-free_grid.c",
    "100-argstostr.c",
    "101-strtow.c",
]

for name in names:
    with open(name, "w") as fb:
        fb.close()
