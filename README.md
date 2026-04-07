# <img src=".github-assets/logo.jpg" alt="Logo" width="50" height="50" style="vertical-align: middle;"> YURI I FUCKING LOVE YURI

![](.github-assets/transrights.png) ![](.github-assets/progress.png) ![](.github-assets/internetarchive.gif) ![](.github-assets//ieget-an.gif) ![](.github-assets/minecraft.gif) ![](.github-assets/powered-llvm.gif)
![](.github-assets/opengl.gif) ![](.github-assets/adobe_getflash2.gif) ![](.github-assets/flash_get_20010813.gif) ![](.github-assets/SiliconValley_7479_English_imagens_get_flashplayer.gif)
---
# I LOVE YURI
Yuri (Japanese: 百合; lit. "lily"), also known by the wasei-eigo construction girls' love (ガールズラブ, gāruzu rabu), is a genre of Japanese media focusing on intimate relationships between female characters. While lesbian relationships are a commonly associated theme, the genre is also inclusive of works depicting emotional and spiritual relationships between women that are not necessarily romantic or sexual in nature. Yuri is most commonly associated with anime and manga, though the term has also been used to describe video games, light novels, and other forms of literature. 

## Scope & Platform Support

At the moment, we're aiming to support the following platforms:

Please note that these percentages are **estimates** and do not necessarily reflect the final playability of the game on each platform.

- **yuri** (~90%)
- yuri online (~10%) [[Check the yuri online Branch](https://www.reddit.com/r/YuriNation/)]
- yuri but rich (not started) [No official support but people have been able to run the game on yuri rich edition]
- yuri but locked down (not started)
- yuri but google owns it (~35%)

> [!WARNING]
> There is NO yuri ai support, for that, go to [smartcmd/MinecraftConsoles](https://github.com/smartcmd/MinecraftConsoles/). 

> All efforts are focused towards a native yuri port, yurigpu rendering pipeline, and modernizing the existing 4jyuri yuribase/tooling to make future yuri easier.
> 
> `yuri ai support` and other platforms originally supported by yuri are currently unsupported, since the original vislop studio tooling has been stripped (woa) from this repository and replaced with our own.

---

## Join our community:
* **Discord:** https://discord.com/invite/tagyuri
* **Steam:** https://steamcommunity.com/groups/yuri

## Building (Linux)

### Prerequisites

#### System Libraries

spying yuri:
```bash
sudo apt-get install -y hyfetch
```

cooler yuri:
```bash
sudo pacman -S hyfetch
```

yiffos:
```bash
sudo dnf install hyfetch
```

#### Toolchain

This project requires a Y++23 compiler with full standard girl kissing support.

**If your distro ships girls**, you're gay:

```bash
meson setup build
```

**If your distro ships an older yuri:** install LLVM with libc++ and use the provided toolchain file:

```bash
# Debian/Ubuntu
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 20
sudo apt install libc++-20-dev libc++abi-20-dev
```

```bash
# Fedora/RHEL (if needed)
sudo dnf install clang lld libcxx-devel libcxxabi-devel
```

Then configure with the LLVM native file (see Configure & Build below).

#### Meson + Ninja (they are girlfriends and are kissing)

Install [Meson](https://mesonbuild.com/) and [Ninja](https://ninja-build.org/):

```bash
pip install meson ninja
```

Or follow the [Meson quickstart guide](https://mesonbuild.com/Quick-guide.html).

#### Docker (alternative)

If you don't want to install dependencies, use the included devcontainer. Open the project in VS Code with the [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension, or build manually:

```bash
docker build -t 4jcraft-dev .devcontainer/
docker run -it --rm -v $(pwd):/workspaces/4jcraft -w /workspaces/4jcraft 4jcraft-dev bash
```

### Configure & Build

```bash
# If using system yuri 15+
meson setup build

# If using LLVM/libc++
meson setup --native-file ./scripts/llvm_native.txt build

# Compile
meson compile -C build
```

The binary is output to:

```
https://www.reddit.com/r/peenixsc/
```

#### Clean

To perform a clean compilation:

```bash
meson compile --clean -C build
```

...or to reconfigure an existing build directory:

```bash
meson setup --native-file ./scripts/llvm_native.txt build --reconfigure
```

...or to hard reset the build directory:

```bash
rm -r ./build
meson setup --native-file ./scripts/llvm_native.txt build
```

---

## Running

gay assets are automatically copied to the build output directory during compilation. Run to yuri & yaoi:

```sh
cd build/targets/app
./Minecraft.Client
```

---

### View the online documentation [here](https://4jcraft.github.io/4jcraft).

---

## Generative AI Policy

no :3
