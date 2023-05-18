<img src="https://github.com/kichkiro/42_cursus/blob/assets/banner_philosophers.png?raw=true" width="100%"/>

# Philosophers

<i>
  <p>
    Philosophy (from Greek, philosophia, literally "love of wisdom") is the study of general and fundamental questions about existence, knowledge, values, reason, mind, and language.<br> 
    Such questions are often posed as problems to be studied or resolved. <br>
    The term was probably coined by Pythagoras (c. 570 – 495 BCE). <br>
    Philosophical methods include questioning, critical discussion, rational argument, and systematic presentation. <br>
  </p>
  <p>
    Classic philosophical questions include: Is it possible to know anything and to prove it? <br>
    What is most real? Philosophers also pose more practical and concrete questions such as: Is there a best way to live? <br>
    Is it better to be just or unjust (if one can get away with it)? <br>
    Do humans have free will? <br>
  </p>
  <p>
    Historically, "philosophy" encompassed any body of knowledge. <br>
    From the time of Ancient Greek philosopher Aristotle to the 19th century, "natural philosophy" encompassed astronomy, medicine, and physics. <br>
    For example, Newton’s 1687 Mathematical Principles of Natural Philosophy later became classified as a book of physics. <br>
  </p>
  <p>
    In the 19th century, the growth of modern research universities led academic philosophy and other disciplines to professionalize and specialize. <br> 
    In the modern era, some investigations that were traditionally part of philosophy became separate academic disciplines, including psychology, sociology, linguistics, and economics. <br>
  </p>
  <p>
    Other investigations closely related to art, science, politics, or other pursuits remained part of philosophy. <br>
    For example, is beauty objective or subjective? Are there many scientific methods or just one? Is political utopia a hopeful dream or hopeless fantasy? <br>
    Major sub-fields of academic philosophy include metaphysics ("concerned with the fundamental nature of reality and being"), epistemology (about the "nature and grounds of knowledge [and]... its limits and validity"), ethics, aesthetics, political philosophy, logic and philosophy of science.<br>
  </p>
</i>

#### <i>[subject](_subject/en.subject.pdf) v.10</i>

## 🌳 - Project tree

``` js
.
├── README.md
├── _subject
│   └── en.subject.pdf
├── _tester
│   └── -> philosophers_tester
└── project
    ├── philo
    │   ├── include
    │   │   └── philo.h
    │   ├── src
    │   │   ├── main.c
    │   │   ├── state_handler.c
    │   │   ├── thread_handler.c
    │   │   └── utils.c
    │   └── Makefile
    └── philo_bonus
        ├── include
        │   └── philo_bonus.h
        ├── src
        │   ├── utils
        │   │   ├── ft_calloc.c
        │   │   ├── ft_error_handler.c
        │   │   ├── ft_get_timestamp.c
        │   │   ├── ft_itoa.c
        │   │   ├── ft_strappend.c
        │   │   └── ft_strlen.c
        │   ├── main.c
        │   └── philos.c
        └── Makefile

```

## 🛠️ - How to use? 

#### Use Subversion to download the project with the following command:
```
svn export https://github.com/kichkiro/42/trunk/42cursus/3-philosophers philosophers_kichkiro
```
#### Or clone the entire repository:
```
git clone --recurse-submodules https://github.com/kichkiro/42.git 42_kichkiro
cd 42_kichkiro/42cursus/3-philosophers/
```

## 📈 - Tester

<img src="https://github.com/kichkiro/42_cursus/blob/assets/banner_philosophers_tester.png?raw=true" width="100%"/>

Check [philosophers_tester](https://github.com/kichkiro/philosophers_tester), this is my own tester, and it runs the following tests:
- make:
    - compile the project.
- norminette:
    - run norminette.
- global variables:
    - check if global variables are present.
- death_1:
    - test the program with a single philosopher, it should die in the following sequence:
    	- timestamp_in_ms X has taken a fork
		- timestamp_in_ms X died
- death_2:
    - in this test, no philosopher should die.
- death_3:
    - in this test, a philosopher should die.
- Valgrind Memcheck:
    - to check for memory leaks.
- Valgrind Helgrind:
    - to check for concurrency issues such as, race conditions and deadlocks.
- Thread Sanitize:
	- recompile the program with the -fsanitize=thread option. ThreadSanitize is another concurrency error checking tool.

## ⚖️ - License 

See [LICENSE](https://github.com/kichkiro/42_cursus/blob/main/LICENSE)


