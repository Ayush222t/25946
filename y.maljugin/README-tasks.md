# Solaris assignments 3-10

All programs are compiled and run on Solaris from their respective directories
with `make`. The generated executables are ignored by Git.

| Task | Program | Example |
| --- | --- | --- |
| 3 | `setuid_test` | `./setuid_test` (see `Task_3/README.md`) |
| 4 | `list_strings` | `./list_strings` (finish input with a line beginning `.`) |
| 5 | `line_lookup` | `./line_lookup ../../Task_5/Task_5.txt` |
| 6 | `line_lookup_alarm` | `./line_lookup_alarm ../../Task_5/Task_5.txt` |
| 7 | `line_lookup_mmap` | `./line_lookup_mmap ../../Task_5/Task_5.txt` |
| 9 | `process_manager` | `./process_manager ../../Task_9/Task_9.txt` |
| 10 | `run_command` | `./run_command sh -c 'exit 7'` |

Task 6 deliberately reuses the line-index implementation from Task 5 and adds
the five-second alarm. Task 7 uses `mmap` instead of `read`/`lseek` for file
access and uses standard I/O for output after the signal handler sets a flag.

The instructor's repository did not contain a Task 8 statement when these
solutions were prepared. No Task 8 solution is invented here.
