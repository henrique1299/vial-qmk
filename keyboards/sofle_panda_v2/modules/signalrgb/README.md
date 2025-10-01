This is an early Work In Progress (WIP) Community module for QMK firmware allowing users to import this module in the userspace as a submodule and include SignalRGB's protocol.

I highly recommend reading the [documentation](https://docs.qmk.fm/features/community_modules) on how to import and build with this.

---

To boil it down though the following should be done in your QMK source / git cloned directory:

mkdir -p modules

git submodule add https://github.com/SRGBmods/QMK_Community_Module modules/signalrgb

git submodule update --init --recursive

To add this module to your build, in qmk source folder/keyboards/**YOUR KEYBOARD**/keymap/**YOUR KEYMAP**/ directory create a file named `keymap.json` with the following content:

```
{
    "modules": [
        "signalrgb"
    ]
}
```

One final note I highly recommend either using the `gen-version.sh` shell script to update the `qmk_version.h` file or manually edit the `qmk_version.h` so that it matches your actual QMK source version.

---

If any manufacturer needs assistance with this source, feel free to open an issue on this Github repo, we're willing to help you.