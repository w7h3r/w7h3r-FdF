# Introduction

FdF is a graphical project developed at **Ecole 42** that renders a 3D height map as a wireframe model in a 2D window using isometric projection.

This project serves as an introduction to graphics programming and 42's graphic library Minilibx. It offers a good balance between algorithmic logic and graphical creativity.

I've found a lot of useful sources while building the program. You can find some of them [here](#sources).

## My Roadmap

I was initially quite confused and unsure where to begin, so here's a basic roadmap I followed throughout the project:

1. **Reading the Map File**
   - Read the map file line by line.
   - Store the height (z-value) and optional color for each point.
   - Convert the raw data into a 2D array or a struct grid.

2. **Initialize MiniLibX**
   - Set up the window and image.
   - Create hooks for key presses or events. For mandatory these are just ESC and window's x symbol button to close the window.

3. **Coordinate System and Scaling**
   - Determine a proper scale based on map dimensions and screen size.

5. **Projection Logic**
   - Convert 3D coordinates (x, y, z) into 2D screen coordinates using **[isometric projection](https://en.wikipedia.org/wiki/Isometric_projection)**.
   - Center the model in the window for better visibility.

    Note: I haven't did a proper centeralization for image because time limits of mine.

6. **Drawing the Wireframe**
   - Use **[Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)** (or any other line-drawing algorithm) to draw lines between adjacent points horizontally and vertically.
   - Assign colors to lines with using color interpolation.

After completing this final step, you should be able to see a wireframe model of your map rendered in 2D, giving the illusion of 3D depth. Don't forget to test your program with various maps.

![9rd91u](https://github.com/user-attachments/assets/4f6b6b50-842c-4ce8-b461-bd5baad0fb1c)

## Bonus

I didn’t have much time to implement the bonus features, so my project does not include zooming, rotation, or other additional -bonus- interactive controls.

Nevertheless when you finish the mandatory part of the project, i assume that you're going to be knowledgable enough about the topics of FdF project. So, when you finish the isometric projection you can make it dynamic.

It's all up to you. If you have enough time and energy for some extra points, go for it.

## Preview

<p align="left">
  <img src="https://github.com/user-attachments/assets/ef430f0c-6bde-4034-9e8a-56974aa35a01" alt="Screenshot 1" height="450"/><br>
  <img src="https://github.com/user-attachments/assets/6e60d77c-5563-42b7-a379-8698f904ea76" alt="Screenshot 2" height="486"/>
</p>

---

## Sources

- https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448  
- https://en.wikipedia.org/wiki/Isometric_projection  
- https://pikuma.com/blog/isometric-projection-in-games  
- https://www.cs.put.poznan.pl/swilk/pmwiki/uploads/Dydaktyka/bresenham-int.pdf  
- https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
