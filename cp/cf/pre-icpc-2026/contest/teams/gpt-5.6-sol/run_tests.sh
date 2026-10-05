#!/usr/bin/env bash
# Runs ./G on the sample fixture and diffs against expected output.
set -uo pipefail
cd "$(dirname "$0")"
if diff -u sample.ans <(./G < sample.in); then
  echo PASS
else
  echo FAIL
  exit 1
fi
