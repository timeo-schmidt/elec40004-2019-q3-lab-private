# Compiling the Controllers
g++ controller_brownian.cpp -o controller_brownian_to_svg_writer && echo "Compiled controller_brownian.cpp"
g++ controller_circle.cpp -o controller_circle_to_svg_writer && echo "Compiled controller_circle.cpp"
g++ controller_spiral.cpp -o controller_spiral_to_svg_writer && echo "Compiled controller_spiral.cpp"

# Running above programs and output into SVG files
./controller_brownian_to_svg_writer > controller_brownian.svg && echo "Generated controller_brownian.svg"
./controller_circle_to_svg_writer > controller_circle.svg && echo "Generated controller_circle.svg"
./controller_spiral_to_svg_writer > controller_spiral.svg && echo "Generated controller_spiral.svg"

exit 0
