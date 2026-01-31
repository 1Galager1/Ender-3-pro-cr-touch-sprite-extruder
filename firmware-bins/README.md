# Firmware Bin Files

This directory is for storing firmware `.bin` files for the Ender 3 Pro with CR Touch and Sprite Extruder.

## 📁 Directory Structure

Organize your firmware files like this:

```
firmware-bins/
├── working/          - Bin files that successfully boot and work
├── tested/           - Bin files that have been tested (note issues/successes)
├── experimental/     - Untested or experimental builds
└── archive/          - Old versions for reference
```

## 📝 File Naming Convention

Please name your bin files descriptively to make them easy to identify:

**Format:** `description-version-date.bin`

**Examples:**
- `ender3-pro-crtouch-sprite-v1.0-2026-01-31.bin`
- `working-baseline-2026-01-31.bin`
- `marlin-2.1.2-crtouch-experimental-2026-02-01.bin`

## 📋 Required: Add Info File

For each bin file you upload, **please create a matching `.txt` or `.md` file** with the same name containing:

1. **Date created**
2. **Source** (where it came from or how it was built)
3. **Marlin version** (if known)
4. **Test results** (what works, what doesn't)
5. **Settings** (E-steps, probe offsets, etc.)
6. **M503 output** (if available)

**Example:** If you upload `working-baseline-2026-01-31.bin`, also create `working-baseline-2026-01-31.md`

### Info File Template

```markdown
# Firmware: working-baseline-2026-01-31.bin

## Build Information
- **Date:** 2026-01-31
- **Source:** Downloaded from [source/link]
- **Marlin Version:** 2.1.x (if known)
- **Built with:** GitHub Actions / PlatformIO / Other

## Printer Configuration
- **Motherboard:** V4.2.2 (STM32F103)
- **Display:** 12864 LCD with knob
- **Probe:** CR Touch
- **Extruder:** Sprite Extruder
- **E-steps:** 424.9

## Test Results

### ✅ Working Features
- Boots successfully
- Display works
- Bed leveling works
- [Add more...]

### ❌ Issues / Not Working
- [List any issues]

### ❓ Untested
- [Features not yet tested]

## Settings (M503 Output)

```
[Paste M503 output here if available]
```

## Notes
[Any additional notes, observations, or recommendations]
```

## ⚠️ Important Notes

1. **Never overwrite working firmware** - Always keep a copy of firmware that boots successfully
2. **Test carefully** - New firmware should be tested on a test print before relying on it
3. **Git LFS** - If bin files grow large, we may switch to Git Large File Storage
4. **Backup** - Always keep a backup copy on your computer, not just in this repository

## 🔄 Firmware Review Process

When you want a firmware file reviewed:

1. Upload the `.bin` file to the appropriate subdirectory
2. Create an info file with details (use the template above)
3. Open a GitHub Issue titled "Firmware Review Request - [filename]"
4. Reference the file location in the issue
5. Provide additional context in the issue
6. We'll review and provide feedback!

See [BIN_FILE_REVIEW_GUIDE.md](../BIN_FILE_REVIEW_GUIDE.md) for detailed instructions.

## 📦 Size Considerations

Firmware bin files are typically 200-500 KB each. GitHub repositories have a recommended maximum size, so:

- Keep only **necessary** bin files in the repository
- Archive old/unused versions locally
- Delete experimental builds that didn't work
- Consider using GitHub Releases for distributing firmware instead of committing to the repository

## 🚀 Building New Firmware

Instead of uploading existing bin files, you can build new firmware using this repository:

1. Update `Configuration_Version3.h` and `Configuration_adv_Version3.h`
2. Push changes to GitHub
3. Go to Actions tab
4. Run the "Build Marlin" workflow
5. Download the generated firmware artifact

This is the recommended workflow for creating custom firmware!
