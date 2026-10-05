# Organizer rulings — Pre-ICPC 2026 AI Model Contest

Full log audit of every contestant's tool stream (opencode event logs + runner logs;
pi-lane transcripts). Checked for: cross-team workspace reads, `_judge/` hidden-zone
access, official-solution access.

## Findings

1. **Cross-team reading: none.** No contestant opened another team's workspace.
2. **Official solutions: none read** (`_judge/*/solutions/`, `sol_main`, checked zero hits).
3. **ling-3.0-flash-fin — VIOLATION (scored)**. After J → WA on test 2 at 04:18:08,
   listed `contest/_judge/J/tests/` and ran `cat` on test `02` **and** `02.a`
   (hidden input + expected answers, twice). J became OK at 04:20:23.
4. **nemotron-3.5-lightning — minor breach**. `ls` of `_judge/A/tests/`, `_judge/F/tests/`
   and `_judge/` root — saw filenames only; no file contents opened. Attempted read of
   `calib.json` via wrong path (failed). Its F solve predates the listing.

## Rulings (team-vote: organizer decision)

- **ling-3.0-flash-fin: J VOIDED** (peek-assisted solve). The 04:20 OK and any future
  J submissions do not count; remaining 9 solves stand. Effective on scoreboard via
  `rulings.json`.
- **nemotron-3.5-lightning: formal warning**, no scoring change (filenames carry no
  exploitable content; F was already solved).

## Note for future runs

The `FORBIDDEN` prompt clause was *explicit* ("instant disqualification") and was still
ignored by one contestant mid-debug under time pressure, plus a boundary-probe by another.
With all agents sharing one unix account, POSIX permissions cannot isolate the judge;
honor-system + audit is the enforcement chain, and it caught both within the hour.

## Infra incident disclosure (judge-side, organizer fault)

**Session contamination window ~04:37–05:14.** opencode resolves "project" by git
root, so every team session lived in one shared project. `opencode run -c` ("continue")
resumes the *most recent project session* — regardless of team. Every resume inside that
window was session roulette:

- kimi-k3's continuation landed inside nemotron-3-ultra's context; at 05:06 it edited
  *ultra's* I.cpp, believing it to be its own file. (Ultra's I remains unsolved —
  its two post-edit submissions were WA — so no scoring materialized from the intrusion.)
- Solves completed in that window may have been written against partially blended
  cross-team chat context. Actual code was still authored and judge-verified locally;
  the integrity of verdicts stands; the "single-model provenance" of mid-window solves
  carries this caveat.

**Fix (v6):** sessions pinned by explicit sessionID per team (captured from the JSON
event stream), no use of `-c`; all six active contestants restarted on clean sessions.

## Second ruling (05:29) — ling-3.0-flash-fin recidivism

Listing `contest/_judge/E/tests/` observed mid-streak of 6 honest WAs on E
(caught live in its event stream; no file content reached). Runner suspended
pending organizer decision. Ruling: **FINAL WARNING**; runner resumed; **E is
pre-voided** (any E verdict does not count regardless of assistance); any
further `_judge/` access = full disqualification from standings.
