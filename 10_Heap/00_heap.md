 ## A heap or Priority queue although represented as a binary tree but implemented as an array or more precisely a dynamic array



                       03

                    /      \

                  /          \

                /              \

              07                10

            /    \            /    \

          /        \        /        \

        12          15    14          21

       /  \        /

     25    29    30





     heap = [3,7,10,12,15,14,21,25,29,30]



### There are two kinds of heaps:

**Min heap**: The smallest value is at the root and both right and left tree have values greater than root, and it is true recursively that means it must be true for every value in tree

**Max heap**: It is opposite of min heapm in this the largest value is at the root and all other values in right and left tree are smaller than root value, and it is true recursively





## There are some properties for a Heap:

1. Structure property: It must be a complete binary tree, means all the level must be filled fully with values there should be no holes, except the last level which can either be full or not.



2. Order property: This is same as min heap and max heap



3. The values are added left to right so there are no holes in it.

    

4. It can have dupes.    





one thing to note is that we don't start at 0th index because then the formula won't work out:

- ### leftChild = 2*i

- ### rightChild = 2*i+1

- ### parent = i/2
As most languages round down the value so i/2 works fine


heap = [3,7,10,12,15,14,21,25,29,30]

### Try to use the formula to get values from the array.