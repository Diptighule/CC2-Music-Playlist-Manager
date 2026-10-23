# Music Playlist Manager --- Doubly Linked List Diagrams

**Course:** CC2 -- Data Structures and Algorithms\
**Language:** C++\
**Data structure:** Doubly Linked List

These diagrams illustrate how the playlist is represented and how common
operations work. Each node stores a song's title and artist, along with
two links:

-   `prev` points to the previous song.
-   `next` points to the next song.
-   `head` points to the first node.
-   `current` points to the song currently selected for playback.

------------------------------------------------------------------------

## 1. Initial Playlist

Example playlist containing three songs:

``` text
head
 |
 v
NULL <- [Song A | Artist A] <-> [Song B | Artist B] <-> [Song C | Artist C] -> NULL
                    ^
                    |
                  current
```

The `prev` link of the first node is `NULL`, and the `next` link of the
last node is `NULL`. In this example, `current` points to Song B.

------------------------------------------------------------------------

## 2. Insertion --- Add a Song at the End

Suppose Song D is added to the playlist.

**Before insertion**

``` text
head
 |
 v
NULL <- [Song A] <-> [Song B] <-> [Song C] -> NULL
```

**After insertion**

``` text
head
 |
 v
NULL <- [Song A] <-> [Song B] <-> [Song C] <-> [Song D] -> NULL
```

The new node is linked after Song C. Song C's `next` points to Song D,
and Song D's `prev` points to Song C. Song D's `next` is `NULL`.

------------------------------------------------------------------------

## 3. Deletion --- Remove a Song

Suppose Song B is deleted from the playlist.

**Before deletion**

``` text
head
 |
 v
NULL <- [Song A] <-> [Song B] <-> [Song C] -> NULL
```

**After deletion**

``` text
head
 |
 v
NULL <- [Song A] <----------------> [Song C] -> NULL
```

After Song B is removed, Song A's `next` points to Song C, and Song C's
`prev` points to Song A. The removed node is no longer part of the list.

------------------------------------------------------------------------

## 4. Next Song Navigation

Suppose `current` points to Song A. Selecting **Next** moves `current`
to Song B by following the `next` link.

**Before**

``` text
[Song A] <-> [Song B] <-> [Song C]
    ^
 current
```

**After selecting Next**

``` text
[Song A] <-> [Song B] <-> [Song C]
                ^
              current
```

If `current` is already at the last song, there is no next node.

------------------------------------------------------------------------

## 5. Previous Song Navigation

Suppose `current` points to Song C. Selecting **Previous** moves
`current` to Song B by following the `prev` link.

**Before**

``` text
[Song A] <-> [Song B] <-> [Song C]
                            ^
                          current
```

**After selecting Previous**

``` text
[Song A] <-> [Song B] <-> [Song C]
                ^
              current
```

If `current` is already at the first song, there is no previous node.

------------------------------------------------------------------------

## 6. Reverse Traversal

Forward traversal starts at `head` and follows `next` links. Reverse
traversal starts at the last node and follows `prev` links.

``` text
Forward:  Song A  --->  Song B  --->  Song C
Reverse:  Song A  <---  Song B  <---  Song C
```

**Forward display order:** Song A, Song B, Song C\
**Reverse display order:** Song C, Song B, Song A

------------------------------------------------------------------------

## 7. Boundary Cases

### Case A --- Empty playlist

``` text
head = NULL
current = NULL
```

There are no songs to display or play. Next and Previous navigation
cannot move to another song.

### Case B --- One song

``` text
head
 |
 v
NULL <- [Song A] -> NULL
          ^
        current
```

The only node has both `prev = NULL` and `next = NULL`. There is no next
or previous song.

### Case C --- Current song is the first song

``` text
[Song A] <-> [Song B] <-> [Song C]
    ^
 current
```

Previous navigation cannot move backward because Song A's `prev` is
`NULL`.

### Case D --- Current song is the last song

``` text
[Song A] <-> [Song B] <-> [Song C]
                            ^
                          current
```

Next navigation cannot move forward because Song C's `next` is `NULL`.

------------------------------------------------------------------------

## 8. Summary

  Operation          Pointer/link action
  ------------------ ----------------------------------------------------
  Add song           Link the new node into the list
  Delete song        Connect the deleted node's previous and next nodes
  Next               Move `current` through `current->next`
  Previous           Move `current` through `current->prev`
  Forward display    Traverse using `next`
  Reverse display    Traverse using `prev`
  Empty-list check   Check whether `head == NULL`

**Note:** Song names such as Song A and Song B are illustrative
placeholders. The actual playlist stores each song's title and artist.
