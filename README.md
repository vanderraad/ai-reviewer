AI-reviewer

**CI: Graphite code review export**

- **Secrets (set in GitHub Actions secrets)**:
  - `GRAPHITE_URL` — Graphite base URL (e.g., `https://graphite.example`)
  - `GRAPHITE_TOKEN` — API token (Bearer) used to query the Graphite render API
  - `GRAPHITE_METRIC` — Metric name for comments (e.g., `ai_reviewer.reviews.comments`)

- **What the workflow does**:
  - On each `push` to `main`, the workflow queries Graphite for the latest value of `GRAPHITE_METRIC` (last 10 minutes), writes a JSON report `code_review_comments.json`, and uploads it as a downloadable artifact named `code-review-comments`.

- **How to use your token**:
  - Add the provided token as the `GRAPHITE_TOKEN` repository secret (Settings → Secrets → Actions).

- **Report format** (`code_review_comments.json`):
```json
{
  "metric": "ai_reviewer.reviews.comments",
  "value": 12.0,
  "timestamp": 1673650000,
  "fetched_at": "2026-01-14T12:00:00Z"
}
```

- **Local test**:
  - You can test the Graphite query locally using `curl`:

```bash
curl -H "Authorization: Bearer $GRAPHITE_TOKEN" "$GRAPHITE_URL/render?target=$GRAPHITE_METRIC&format=json&from=-10min&until=now" | jq '.'
```

- **Notes**:
  - The workflow expects the Graphite API to accept a Bearer token in the `Authorization` header. If your Graphite instance uses a different auth header, update `.github/workflows/graphite.yml` accordingly.

