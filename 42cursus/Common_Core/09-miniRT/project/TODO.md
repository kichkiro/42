# TODO

## bugs ---------------------------------------------------------------------->

- [v] get_sphere non funziona (segmetation fault): `./project/src/sphere.c:15`
- [ ] shadow renders through another object (try test.rt)
- [ ] shadow is a bit "too big" (try test.rt)
- [ ] shadow should be black, regardless of object color

## kichkiro ------------------------------------------------------------------>

- [v] leaks parser
- [v] gestire errori in caso di scena invalida
- [v] spostare definizione lista in minirt.h
- [v] ri-aggiungere libft e minilbx (puoi aggiungerle come submodule per
		evitare ridondanze di file)
- [v] file sorgente, header e Makefile
- [v] il Makefile di miniRT deve compilare le librerie direttamente
- [v] Invalid read of size 1 at: get_value (get_value.c:21)

- [ ] PARSING
	- [ ] Una scena per essere valida deve contenere: Ambient light, Camera,
		  Luce, massimo 1 oggetto per tipo, altrimenti stampa "Error\n"
	- [v] i colori degli oggetti sono invertiti, [255,0,255] dovrebbe essere
		  viola, ma ritorna giallo (hai invertito il verde con il blu nel
		  parsing)

- [v] aggiungere un campo a t_scene per tenere traccia del tipo di oggetto
	  (proporrei un enum, piu' elegante, ma non so se e' conforme alla norma,
	  anche una macro o una stringa puo' andare bene) e rendere l'id univoco
	  per ogni singolo oggetto.

- [v] Light management
	- [x] spot brightness
	- [x] hard shadows
	- [x] ambient lighting
	- [x] diffuse lighting

## anvannin ------------------------------------------------------------------>

- [x] libreria vector
	- [x] Makefile
	- [x] spostare struttura t_coords in vector.h
	- [x] funzioni base
		- [x] distanza tra due punti
		- [x] addizione e sottrazione
		- [x] prodotto scalare
		- [x] prodotto incrociato
	- [x] funzioni avanzate
		- [x] modulo
		- [x] normalizzazione
		- [x] seno e coseno
		- [x] rotazioni

- [x] Window
	- [x] init
	- [x] close and destroy
	- [x] labels
		- [x] object rotation
		- [x] resize height/width individually
	- [x] update

- [x] Transformations
	- [x] traslate
		- [x] sphere
		- [x] cylinder
		- [x] camera
	- [x] scale
		- [x] spere
		- [x] cylinder
			- [x] height
			- [x] diameter
	- [x] rotate
		- [x] cylinder
		- [x] camera

- [x] when moving the first object, for the first time, the second object
	moves instead (try test.rt)

- [x] when multiple objects are present, the shadow of the first object is
	rendered after moving the second object

- [x] shadow of the cylinder is not rendered

- [x] render cylinder at an angle (correctly renders the base of the cylinder,
	but not the body)
- [x] rotation of the camera stretches along a single axis

## Bonus -------------------------------------------------------------------->

- [ ] Add specular reflection to have a full Phong reflection model.

- [ ] Color disruption: checkerboard.

- [ ] Colored and multi-spot lights.

- [ ] One other 2nd degree object: Cone, Hyperboloid, Paraboloid..

- [ ] Handle bump map textures

### Extras ------------------------------------------------------------------->
- [ ] logs in miniRT.log file instead of terminal
- [ ] R key to reset scene
- [ ] Anti aliasing
- [ ] get selected object by clicking on it with the mouse
- [ ] read # as comment for .rt files, therefore ignore the object
- [ ] Render light as little mono-color sphere
	- [ ] for mandatory always white rays
