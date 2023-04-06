<img src="https://github.com/kichkiro/42_cursus/blob/assets/banner_push_swap.png?raw=true" width="100%"/>

# Push Swap

<i>
    "The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.
    <br>You have at your disposal a set of integer values, 2 stacks, and a set of instructions
    to manipulate both stacks.
    <br>Your goal? Write a program in C called push_swap which calculates and displays
    on the standard output the smallest program, made of Push swap language instructions,
    that sorts the integers received as arguments.
    <br>Easy?
    <br>We’ll see.."
</i>

#### <i>[subject](_subject/en.subject.pdf) v.6</i>

## 🌳 - Project Tree 

```js
├── README.md
├── project
│   ├── Makefile
│   ├── include
│   │   └── push_swap.h
│   ├── lib
│   │   └── libft
│   └── src
│       ├── push_swap.c
│       ├── perform_actions.c
│       ├── algorithm_short.c
│       ├── algorithm_long.c
│       ├── find_best_path.c
│       ├── checker.c  
│       └── lst
│           ├── t_stack_add_back.c
│           ├── t_stack_check_dup.c
│           ├── t_stack_del_last.c
│           ├── t_stack_free.c
│           ├── t_stack_from_arr.c
│           ├── t_stack_head.c
│           ├── t_stack_index_data.c
│           ├── t_stack_is_sorted.c
│           ├── t_stack_last.c
│           ├── t_stack_max.c
│           ├── t_stack_min.c
│           ├── t_stack_new.c
│           ├── t_stack_n_is_inside.c
│           ├── t_stack_second_min.c
│           ├── t_stack_set_to_head.c
│           ├── t_stack_size.c
│           └── t_stack_to_arr.c
└── _subject
    ├── checker_linux
    ├── checker_Mac
    └── en.subject.pdf
```

## 🛠️ - How to use? 

#### Use Subversion to download the project with the following command:
```
svn export https://github.com/kichkiro/42/trunk/42cursus/2-push_swap push_swap_kichkiro
rm -rf push_swap_kichkiro/project/lib/libft
svn export https://github.com/kichkiro/42/trunk/42cursus/0-libft/libft push_swap_kichkiro/project/lib/libft
```
#### Or clone the entire repository:
```
git clone https://github.com/kichkiro/42.git 42_kichkiro
cd 42_kichkiro/42cursus/2-push_swap/
```

## 📈 - Sorting Algorithms

### Algorithm for numbers >= 2 && <= 5

The algorithm works as follows:
- If the number of elements is greater than 3, the smallest excess 
    elements are transferred to stack 'b' in the least number of actions and
    sorted in descending order;
- When there are 3 or less elements in stack 'a', the goal of the 
    algorithm is to locate the largest element and move it with a single 
    action to the last node;
- If the element at the first node is greater than the second element they 
    are swapped;
- Finally (if there are elements in stack 'b') the two stacks are merged.

### Algorithm for numbers > 5

The algorithm is divided into three steps:
- In the first phase all the elements that are not part of the longest 
    incremental subsequence are transferred to stack 'b';
- As long as stack 'b' is not empty, each time the element that "costs" 
    less in terms of actions is identified and transferred;
- Finally, if the smallest element is not on the first node, the list is
	    rotated.

## 📉 - Benchmark

[push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

<img src="https://github.com/kichkiro/42_cursus/blob/assets/push_swap_visualizer.gif?raw=true" alt="push_swap_visualizer" width="100%"/>

[push_swap_tester](https://github.com/LeoFu9487/push_swap_tester)

<img src="https://github.com/kichkiro/42_cursus/blob/assets/push_swap_tester.png?raw=true" alt="push_swap_tester" width="100%"/>

## ⚖️ - License

See [LICENSE](https://github.com/kichkiro/42_cursus/blob/main/LICENSE)
