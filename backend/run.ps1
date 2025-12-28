$ErrorActionPreference = "Stop"

# Build first
Write-Host "Building..."
& ./build.ps1

if ($LASTEXITCODE -eq 0) {
    Write-Host "Starting application..."
    Set-Location build
    ./budget_tracker.exe
}
else {
    Write-Host -ForegroundColor Red "Build failed, not running."
}
