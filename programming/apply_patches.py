import os, subprocess

env = DefaultEnvironment()


def patch_library(library_path):
    project_dir = env["PROJECT_DIR"]
    print(project_dir)
    # Change the current working directory
    previous_cwd = os.getcwd()
    # os.chdir(project_dir)
    # Example: Add a line to a specific header file
    header_file = os.path.join(library_path, "src", "Keypad.cpp")
    patch_file = os.path.join(os.path.curdir, "patches", "add-hold-detection.patch")
    if not os.path.isfile(patch_file):
        print(f"Patch file not found: {patch_file}")
        return

    if os.path.exists(header_file):
        result = env.Execute(f"patch -p1 < {patch_file}")
        # Check for errors    if result != 0:
        print(f"Error applying patch. Result: {result}")
    else:
        print("Patch applied successfully.")
    # Change back to the previous working directory
    os.chdir(previous_cwd)


def main():
    # Path to the library you want to patch
    library_path = os.path.join(env["PROJECT_LIBDEPS_DIR"], env["PIOENV"], "Keypad")
    patch_library(library_path)


main()
