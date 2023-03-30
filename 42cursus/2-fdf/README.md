<img src="https://github.com/kichkiro/42_cursus/blob/assets/banner_fdf.png?raw=true" width="100%"/>

# FDF

<i>
	<p>
		The representation in 3D of a landscape is a critical aspect of modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest.
	</p>
	<p>
		As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these phenomena and their evolution, and as a result, be better prepared.
	</p>
	<p>
		It’s your turn today to modelize some 3D magnificent landscapes, imaginary or not.
	</p>
</i>

#### <i>[subject](_subject/en.subject.pdf) v.2</i>

## 🌳 - Project Tree 

```js
├── README.md
├── project
│   ├── Makefile
│   ├── include
│   │   └── fdf.h
│   ├── lib
│   │   ├── libft
│   │   └── libmlx
│   ├── maps
│   │   ├── 100-6.fdf
│   │   ├── 10-2.fdf
│   │   ├── 10-70.fdf
│   │   ├── 20-60.fdf
│   │   ├── 42col.fdf
│   │   ├── 42.fdf
│   │   ├── 50-4.fdf
│   │   ├── basictest.fdf
│   │   ├── elem2.fdf
│   │   ├── elem-col.fdf
│   │   ├── elem.fdf
│   │   ├── elem-fract.fdf
│   │   ├── julia.fdf
│   │   ├── mars.fdf
│   │   ├── pentenegpos.fdf
│   │   ├── plat.fdf
│   │   ├── pnp_flat.fdf
│   │   ├── pylone.fdf
│   │   ├── pyra.fdf
│   │   ├── pyramide.fdf
│   │   ├── t1.fdf
│   │   └── t2.fdf
│   └── src
│       ├── clean.c
│       ├── draw.c
│       ├── fdf.c
│       ├── hooks.c
│       └── lst
│           ├── t_map_add_back.c
│           ├── t_map_copy_lst.c
│           ├── t_map_free.c
│           ├── t_map_get_map.c
│           ├── t_map_get_size.c
│           ├── t_map_move_to_index.c
│           ├── t_map_new.c
│           └── t_map_set_to_head.c
└── _subject
    ├── en.subject.pdf
    ├── fdf
    ├── fdf_linux
    ├── maps.zip
    ├── minilibx-linux.tgz
    ├── minilibx_macos_sierra_20161017.tgz
    ├── minilibx_mms_20191025_beta.tgz
    └── sources.tgz
```

## 🛠️ - How to use? 

#### Use Subversion to download the project with the following command:
```
svn export https://github.com/kichkiro/42/trunk/42cursus/2-fdf fdf_kichkiro
rm -rf fdf_kichkiro/project/lib/libft
svn export https://github.com/kichkiro/42/trunk/42cursus/0-libft/libft fdf_kichkiro/project/lib/libft
```
#### Or clone the entire repository:
```
git clone https://github.com/kichkiro/42.git 42_kichkiro
cd 42_kichkiro/42cursus/2-fdf/
```

## ⚖️ - License

See [LICENSE](https://github.com/kichkiro/42_cursus/blob/main/LICENSE)
