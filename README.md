# Symbiotic-Launcher-hybrid
Symbiotic Bot Launcher: ported from C# WPF (XAML) to C++ ultralight (HTML/CSS/JS)

1. only once
cmake -B build
cmake --build build --config Release

2. set alias to .zshrc
alias ab='cmake --build build --config Release --clean-first'
