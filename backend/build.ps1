# Windows Build Script for Monthly Budget Tracker

$ErrorActionPreference = "Stop"

$BUILD_DIR = "build"
$DATA_DIR = "../data"
$TARGET = "$BUILD_DIR/budget_tracker.exe"
$SOURCES = "src/main.cpp"
$CXXFLAGS = "-std=c++17 -Wall -Wextra -I./src"

# Kill running instance if exists
$PROCESS_NAME = "budget_tracker"
$proc = Get-Process $PROCESS_NAME -ErrorAction SilentlyContinue
if ($proc) {
    Write-Host "Stopping running instance of $PROCESS_NAME..."
    Stop-Process -Name $PROCESS_NAME -Force
    Start-Sleep -Seconds 1
}

Write-Host "Setting up directories..."
if (!(Test-Path -Path $BUILD_DIR)) {
    New-Item -ItemType Directory -Path $BUILD_DIR | Out-Null
    Write-Host "Created $BUILD_DIR directory."
}
if (!(Test-Path -Path $DATA_DIR)) {
    New-Item -ItemType Directory -Path $DATA_DIR | Out-Null
    Write-Host "Created $DATA_DIR directory."
}

Write-Host "Compiling..."
$compileCommand = "g++ $CXXFLAGS $SOURCES -o $TARGET"
Write-Host "Running: $compileCommand"

try {
    Invoke-Expression $compileCommand
    Write-Host -ForegroundColor Green "Build successful! Executable created at $TARGET"
}
catch {
    Write-Host -ForegroundColor Red "Build failed!"
    exit 1
}
