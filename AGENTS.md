# AGENTS.md

## Repository overview

Personal learning repo ("nlbq") — C language notes, Python exercises, HTML examples, and a minesweeper game.

## Directory structure

- `clearn/c语言笔记/` — C language study (subfolders: `c_learn/`, `game/`, `nlbq/`)
- `clearn/c语言笔记/game/` — Minesweeper game (Visual Studio 2022, `game.sln`)
- `pythonlearn/` — Python practice scripts (no framework, standalone `.py` files)
- `Weblearn/` — HTML examples
- `chat/` — drawio diagrams
- `imgs/` — image assets

## Build & run

- **C projects**: Built with Visual Studio 2022 (`.sln` / `.vcxproj`). No CLI build — open `.sln` in VS.
- **Python scripts**: Run directly with `python <file>.py`. No virtualenv or dependencies declared.
- **No tests, linting, or CI** configured anywhere.

## Conventions

- All content is in Chinese (comments, filenames, README).
- `.gitignore` excludes `.exe`, `.sln`, `.vcxproj`, `.filters`, `.user`, `Debug/`, `Release/`, `.vs` — but some are already tracked.
- Encoding issues in `.c` files: some have GBK comments that display as mojibake in UTF-8 contexts.

## Notes for agents

- This is a study repo, not a production codebase. Treat all code as example/learning code.
- No package manager, no lockfiles, no dependency management.
- The minesweeper game (`game/game/game.c`) is the only multi-file C project; everything else is standalone.
