
##   extended list

A student project created on 04.2022 implements a list.

 ### Commands
 
### 1) `P x`
displays element of the list

**parameters:**

x:
- if x is a number - displays the value in the node pointed by the xth indicator (0-9)
- if x is a ALL - displays all list nodes

### 2) `R x`
removes the node pointed by the xth (0-9) indicator

### 3) `.A x y`
adds the new node `y` before iterator `x`

**parameters:**

 y - added number 
 
 x - place to add a number: 
- if index is a number, value y will be added before the node pointed by the xth indicator (0-9) on the list,
- if index is a BEG/END value, value y will be added before the top/end of the list.

### 4) `A. x y`
adds the new node with value `y` after iterator `x`

**parameters:**

 y - added number 
 
 x - place to add a number: 
- if index is a number, value y will be added after the node pointed by the xth indicator (0-9) on the list,
- if index is a BEG/END value, value y will be added after the top/end of the list.

### 5) `i x y`
sets a new indicator (There are 10 indicators pointing to a given node on the list)

**parameters:**

y -  place the indicator should point to

x - number of indicator (0-9)
- if y is a number, indicator will be set to the xth position of the list,
- if y is a BEG/END value, indicator will be set to the top/end of the list.

### 6) `- index`
moves the indicator one node back

**parameters:**

index - number of indicator (0-9)

### 7) `+ index`
moves the indicator one node forward

**parameters:**

index - number of indicator (0-9)

 ### Example
 ```
 A. BEG 1
A. BEG 2
A. BEG 3
P ALL
.A BEG 0
P ALL
i 0 BEG
A. 0 111
P ALL
+ 0
+ 0
A. 0 222
P ALL

 result:
1  3  2
0  1  3  2
0  111  1  3  2
0  111  1  222  3  2
 ```
 
 
## Setup
#### How to run project
1. Clone this repository.
2. Open the project solution file (`.sln`) with Visual Studio.
3. Build and run the project.

