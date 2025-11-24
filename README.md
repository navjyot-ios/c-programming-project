Simple Traffic Violation & Penalty Management (Beginner)

Overview
--------
This is a simple C project implemented in a beginner-friendly style (suitable for a 1st semester B.Tech student).
It provides an in-memory demonstration of vehicle registration, recording violations, marking payments, and viewing basic reports.

Project structure
-----------------
- include/
  - vehicle.h
  - violation.h
  - reports.h
  - penalty.h
- src/
  - main.c
  - vehicle.c
  - voilation.c   (note: filename kept as-is)
  - reports.c
  - penalty.c
- program (built executable after compilation)

Build (macOS / Linux)
---------------------
From the project root run:

```bash
gcc -I include -o program src/*.c
```

This compiles all source files and creates an executable named `program` in the project root.

Run
---
Start the program from the project root:

```bash
./program
```

The menu is simple and interactive. Example quick-run to auto-exit:

```bash
printf "0\n" | ./program
```

Notes
-----
- The code is intentionally simple and uses in-memory arrays for storage (no external database/files for core operations) so it's easy to read and extend.
- Some filenames include small misspellings (e.g., `voilation.c`). They were left unchanged to avoid breaking includes; feel free to rename them and update includes.
- If you want persistence (save/load vehicles and violations), I can add simple text-file storage in a follow-up change.

Next steps (suggested)
----------------------
- Add file-based persistence for vehicles and violations.
- Fix file name spellings if desired.
- Add a `Makefile` to simplify builds: `make` / `make clean`.
- Add small tests or example data files.

Contact
-------
If you want me to implement persistence or rename files, tell me which change to do next and I'll update the code.
