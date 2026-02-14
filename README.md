# Windows Media Controls (win_media_controls)

A lightweight Windows utility that maps **Ctrl+Right** and **Ctrl+Left** to media **Next Track** and **Previous Track** keys.

This minimal background process allows you to nativage media on Windows with simple keyboard shortcuts for keyboards without dedicated media keys.

## Getting Started

### Download

Download the latest `win_media_controls.exe` from the **[Releases](../../releases)** page.

### Build (Optional)

To modify or recompile the script yourself.

Requires any C++ compiler targeting Windows (e.g. [w64devkit](https://github.com/skeeto/w64devkit/releases), MinGW, or MSVC).

```bash
g++ win_media_controls.cpp -o win_media_controls.exe -mwindows
```

## Usage

1. Run `win_media_controls.exe`
2. Use **Ctrl+Right** → Next Track
3. Use **Ctrl+Left** → Previous Track

### Run at Startup
1. Place `win_media_controls.exe` in a permanent location (e.g. `C:\Program Files\WinMediaControls\`)
2. Press `Win+R`, type `shell:startup`, and hit Enter
3. Create a shortcut to `win_media_controls.exe` in that folder

## License

MIT