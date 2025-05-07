import glob
import sys

# Collect all .cpp files excluding stb_image.cpp to avoid duplicate definitions
cpp_files = sorted(
    [f.replace('\\', '/') for f in glob.glob('src/**/*.cpp', recursive=True)]
)
cpp_files += glob.glob('thirdparty/imgui/*.cpp')
cpp_files += [
    'thirdparty/imgui/backends/imgui_impl_glfw.cpp',
    'thirdparty/imgui/backends/imgui_impl_opengl3.cpp'
]

# Exclude the standalone stb_image.cpp since resource_manager.cpp defines the implementation
cpp_files = [p for p in cpp_files if not p.endswith('core/stb_image.cpp')]

if not cpp_files:
    print("Error: No .cpp files found.")
    sys.exit(1)

with open('Makefile', 'w') as f:
    f.write('CXX = g++\n')
    f.write('CXXFLAGS = -I./thirdparty/imgui -I./thirdparty/imgui/backends -I./src -Wall -std=c++17\n')
    f.write('LDFLAGS = -lopengl32 -lglfw3 -lglew32\n\n')
    f.write('SRCS := \\\n')
    for path in cpp_files[:-1]:
        f.write(f'\t{path} \\\n')
    f.write(f'\t{cpp_files[-1]}\n\n')
    f.write('TARGET = game\n\n')
    f.write('all:\n')
    f.write('\t$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)\n\n')
    f.write('clean:\n')
    f.write('\t-rm -f $(TARGET)\n\n')
    f.write('run: all\n')
    f.write('\t./$(TARGET)\n')

print("Makefile regenerated successfully.")
