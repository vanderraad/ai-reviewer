AI-reviewer

**CI: SonarQube**

- **Secrets**: Add the following repository secrets (Settings → Secrets → Actions): `SONAR_HOST_URL` (your SonarQube server URL) and `SONAR_TOKEN` (a user token with scanner/analysis permissions).
- **When it runs**: The workflow runs on `push` to `main`/`master` and on `pull_request`.
- **Runner requirements**: The job uses the `sonarsource/sonar-scanner-cli` Docker image, so the runner must support Docker (GitHub's `ubuntu-latest` does).
- **PR decoration**: To enable PR decoration/comments you need SonarQube Developer Edition (or SonarCloud with PR analysis). Configure the SonarQube instance for your project accordingly.
- **Local test**: You can run a local scan (example):

```bash
docker run --rm -e SONAR_HOST_URL="https://your-sonarqube" -e SONAR_TOKEN="YOUR_TOKEN" -v "$PWD":/usr/src -w /usr/src sonarsource/sonar-scanner-cli -Dsonar.projectKey="your/project" -Dsonar.sources=.
```
