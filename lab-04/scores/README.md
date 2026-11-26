# Lab-04 · Software Development Processes · Team CertifiedVibeCoder

## Files of this lab
| File | Task | Description |
|------|------|-------------|
| fundamental-activities.md | 1 | The four fundamental activities in Club Hub: leads, weeks, artifacts, Done-when criteria, 12207 processes and loops |
| scores/*.md | 2 | Individual process-model scores, one file per member, committed before the team discussion |
| process-comparison.md | 2 | Team weights, agreed scores, weighted results, sensitivity check and conclusion for waterfall, incremental and Scrum-style |
| process-decision.md, process.mmd | 3 | PDR-001 (process decision with tailoring table) and the Mermaid process diagram |
| iteration-plan.md | 4 | Gantt chart for weeks 5 to 14, iteration goals and sprint capacity |
| reuse-inventory.md | 5 | Make-or-reuse table, licence check and build verification output |
| ../CMakeLists.txt | 5 | FetchContent: googletest v1.17.0, rapidcsv v8.84 |
| ../tests/csv_smoke_test.cpp, ../tests/data/events.csv | 5 | Smoke test proving the reused libraries build and link |
| v-model-trace.md, cmmi-reflection.md | Challenge | V-model trace with boundary values, two Gherkin scenarios, (optional) passing unit tests, honest CMMI reflection with a measurable target. |

## Inputs reused
| Input | File | Version (commit) |
|-------|------|------------------|
| Team charter | lab-01/team-charter.md | Branch `main` |
| Problem statement | lab-01/problem-statement.md | Branch `main` |
| Application type | lab-02/application-type.md | Branch `main` |
| Repository licence | LICENSE | Branch `main` (MIT) |

## Dependencies added
| Library | Version | Licence | Purpose |
|---------|---------|---------|---------|
| GoogleTest | v1.17.0 | BSD-3-Clause | Unit-test framework for the registration rules |
| rapidcsv | v8.84 | BSD-3-Clause | Header-only CSV reader for the event and registration storage |

Both are fetched with CMake FetchContent at pinned versions and are compatible with our MIT licence (see `reuse-inventory.md`).

## Change log
| Date | Change | By |
|------|--------|----|
| 2026-11-26 | Lab-04: PDR-001 accepted, iteration plan for weeks 5-14, reuse inventory, FetchContent dependencies (GoogleTest, rapidcsv) and smoke test | Team CertifiedVibeCoder |