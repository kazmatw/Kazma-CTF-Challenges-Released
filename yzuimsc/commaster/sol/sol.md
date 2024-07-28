# Writeup

## Extract the file
```bash
# First, look at the help information for the tar command to find out how to extract the file.
tar --help | head

# Extract the contents of commaster.tar.
tar -xf commaster.tar
```

## Observe the challenge
```bash
# Go into the challenge directory.
cd commaster/

# List the contents of the directory. You can see flag_part1. Based on the naming pattern, you can guess that the other two parts are named flag_part2 and flag_part3.
ls

# Display the contents of flag_part1.
cat flag_part1
```

## Grep or Find
You can use any of the commands below to find all the parts of the flag.
```bash
# Grep all file content that is not empty.
grep -rv " "

# Use find with -exec to concatenate the contents of the found files, or you can just find them and concatenate manually.
find . -name "flag_*" -exec cat {} +

# Alternatively, you can use:
find . -name "flag_*" -exec cat \;

# Or:
find . -name "flag_*" | xargs cat
```
