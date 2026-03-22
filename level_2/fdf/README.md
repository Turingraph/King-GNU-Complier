# Description

This is FdF from 42 coding school assignment. FdF is about converting the `.fdf` files with the columns of integer to 3D isometric wireframe, and display it on 2D screen using XML42 library.

I add the following features for bonus part
1.	`--bonus` option for display 3D object with the following default bonus features
2.	Z Buffer calculation, so the only surface of the object that are in front of another surface will be shown accordingly.
3.	coloring based on the angle between cross project vector of 2D triangles, and the light vector
4.	quaternion rotation of 3D object and light source. (I have to design how user specify the rotation of the 3D object and light source later)
5.	`--prism` so the 3D model will looks like prism instead of chocolate as seen in most FdF project.
6.	`--not_sharp` to make duplicated integer and integer array to make isometric projection less "sharp" for example `0 1 0` -> `0 0 1 1 0 0` (which have plateau than sharp mountain).
7.	Display 3D input text when use `./fdf "Hello World"` and make the color of light based on FIGlet ASCII files input (`text/a.txt`, `text/b.txt` etc.) If there is no target files, then return the error.
8.	`--Adir` option to specify which folder that have `dir/a.txt`, `dir/b.txt`, etc. to include for `./fdf "Goodbye Mars"` input.
9.	`--obj_rgb=#FF0000`, `--background_rgb=#000000`, and `--light_rgb=#FFFFFF` to specify the color of 3D object, background, and light, accordingly. The default color of objects, background, and light, are red, black, and white, accordingly.
10.	`synesthesia.txt` as 1 column text to color object based on user defined graphite color synesthesia as the default color of 3D object (instead of red in 9-th feature), is based on the color of the first character of user string/file name input. If `synesthesia.txt` file don't exists in the current directory, than the default color of the object is red.

Here is the example of `synesthesia.txt`

```
#FFFFFF
#000000
#b58b1b
... from 0-9 and A-Z. The color of low case and capital case are the same. If the text in i-th line is invalid, then the default color of i-th character is #666666
#4e4736
```

I add those features because MiniRT is the project about displaying light interaction with 3D object, so I can reuse some of my code in this future project. 

Even through, people can use Blender and/or Gen AI model to create the rotated 3D prism/text interacting with light, Blender is hard to use and Gen AI art tool don't have deterministic behavior, so this project is suitable for user who just want to convert ASCII text/art into simple 3D model that interacting with light. I will make this app compatible with Blender in the future.

## How to download this project ? (EMPTY)

## Basic user tutorial (EMPTY)

## Folder Structure

Here is the directory structure
1.	`build/` for computing the binary files
2.	`doc/` for user tutorial, installation tutorial, and explaining how 3D graphic related algorithms work.
3.	`examples/` for showing my 4 artworks
	1.	Gen AI Artwork (a.k.a. `examples/ai_art/`) that have my 3D Graffiti visual components. This is the only artwork that is made by AI, and other artworks aren't made by AI and made by me.
	2.	Photo of my physical drawing (a.k.a. `examples/draw_art/`) that use 3D Graffiti visual components as drawing reference.
	3.	Photo (a.k.a. `examples/photo_art/`) that have my 3D Graffiti visual components by photo editing.
	4.	Pixel Art (a.k.a. `examples/pixel_art/`) that have my 3D Graffiti visual components.
4.	`include/` for including the header files and other files of the static library including `libft.h`, `libft/`, `glfw/`, `MLX42.h`, `MLX42/`, and `get_next_line.h`. Note that I don't include some library in this Git repo e.including `glfw/` and `MLX42/`, but include it in my PC anyway. I will use static library for the early version of this project and might migrate as dynamic library later.
5.	`input/` for checking if my project works with fdf files, `synesthesia.txt`, `alphabet/a.txt` and txt files correctly.
6.	`src/` for the source code of this project.

# Instructions (EMPTY)

## Check if my project follow the subject requirement (EMPTY)

## Check memory leak with Valgrind (EMPTY)

# Additional Information

1.	`doc/dev_plan_0_introduction.md` is about Graphic Rendering Pipeline and my Project Plan for the MVP version.
2.	`doc/synesthesia.md` is about what is synesthesia ?
3.	`doc/user_tutorial.md` for more user tutorial.

# Resource (UNFINISHED)

1.	`ascii/`
2.	import MXL42 library.
3.	`tessellation/`
4.	`rasterization/`
5.	`rotation/`
6.	`cli/`
7.	Synesthesia
8.	basic computer graphic
9.	Art tool
	1.	Stable Diffusion
	2.	Piskel
	*	https://www.piskelapp.com/p/create/sprite/
