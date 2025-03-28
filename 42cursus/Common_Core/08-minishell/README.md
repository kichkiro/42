
<img src="https://github.com/kichkiro/42_cursus/blob/assets/banner_minishell.png?raw=true" width="100%"/>

# Minishell

<i>
	<p>
		The existence of shells is linked to the very existence of IT.
	</p>
	<p>
		At the time, all developers agreed that communicating with a computer using aligned 1/0 switches was seriously irritating.
	</p>
	<p>
		It was only logical that they came up with the idea of creating a software to communicate with a computer using interactive lines of commands in a language somewhat close to the human language.
	</p>
	<p>
		Thanks to Minishell, you’ll be able to travel through time and come back to problems people faced when Windows didn’t exist.
	</p>
</i>

#### <i>[subject](_subject/en.subject.pdf) v.6</i>

## 🌳 - Project tree

``` js
.
├── LICENSE
├── README.md
├── _notebook
│   ├── bash.ipynb
│   └── minishell.ipynb
├── _subject
│   └── en.subject.pdf
├── _tester
│   └── -> minishell_tester
└── project
    ├── Makefile
    ├── readline.supp
    ├── include
    │   └── minishell.h
    ├── lib
    │   ├── libft.a
    │   └── libft.h
    └── src
        ├── _lst
        │   ├── lst_add_back.c
        │   ├── lst_free.c
        │   ├── lst_free_last.c
        │   ├── lst_new.c
        │   ├── lst_set_to_head.c
        │   └── lst_set_to_last.c
        ├── main
        │   ├── bombfreeall.c
        │   ├── history.c
        │   ├── init.c
        │   ├── main.c
        │   ├── prompt.c
        │   └── signal_handler.c
        ├── parser
        │   ├── parsing_ext.c
        │   ├── parsing_system.c
        │   ├── variable_expand.c
        │   └── wildcards.c
        ├── executor
        │   ├── booleans.c
        │   ├── builtins.c
        │   ├── execution_system.c
        │   ├── fd_handler.c
        │   ├── heredoc.c
        │   ├── pipes.c
        │   └── redirections.c
        ├── errors
        │   ├── errors_handler.c
        │   ├── invalid_prompt.c
        │   └── syntax_errors.c
        └── variables
            ├── env_variables.c
            ├── export_variables.c
            └── shell_variables.c
```

## 🛠️ - How to use?

```
git clone https://github.com/kichkiro/minishell.git
cd minishell/project
make
./minishell
```
### and enjoy yourself...

<img src="https://github.com/kichkiro/42_cursus/blob/assets/prompt_minishell.gif?raw=true" width="100%"/>

## 📈 - Tester

The tester [minishell_tester](https://github.com/kichkiro/minishell_tester) performs more than 200 tests on the main features of the project, including:

- Parsing
- Commands
- Redirects
- Pipes
- Exit Status
- Mixed Mandatory
- Booleans
- Wildcards

The tester launches Bash and Minishell processes with the Popen method of Python's subprocess library, inputs the same test, captures the output, and compares it.

<img src="https://github.com/kichkiro/42_cursus/blob/assets/minishell_tester_usage.gif?raw=true" width="100%"/>

NOTE: The tester was tested on Ubuntu 20.04 LTS with Python version 3.8.
Also, during development we tried to make it as generic as possible so that it can work on other minishell projects, but this does not guarantee that it will work correctly on all projects.

## ⚖️ - License

See [LICENSE](LICENSE)
