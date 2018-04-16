# reason-native-starter

[`Reason`](http://reasonml.github.io/) project for native compilation:

[More info on the workflow](https://reasonml.github.io/guide/native).

## Develop With OPAM

**Build**:

Clone the repo and run these commands from within the project:

```sh
opam update # get the latest opam packages data. Skip this optionally
# opam will read into the `opam` file and add the other dependencies
opam install reason
opam install merlin
opam install re
make build    # build/rebuild your files
```

**Run**:

```sh
make run
```

**Develop**:
- Make sure you have `merlin` globally installed (via opam, *not*
  `reason-cli`!)
- [See the ReasonML
  docs](https://reasonml.github.io/docs/en/editor-plugins.html) about setting
  up your editor. Just remember to *not* install `reason-cli` when using
  `opam`.



## Preliminary Esy Support
You may alternatively use [`esy`](http://esy.sh/) to build and develop this
project. (`esy` is like "npm for native"). This is preferable for people who
want to build native Reason projects using existing opam packages, but with a
more familiar and sandboxed workflow. This is experimental and not stable yet.
Please report any issues to [the esy repo](https://github.com/esy/esy).

**Build**:

```sh
npm install -g esy@latest
esy install
esy build
```

**Run**:

Use `esy x` ("esy execute") command to run the binary.

```sh
esy x reason-native-bin
```

**Develop**:

- [See the ReasonML
  docs](https://reasonml.github.io/docs/en/editor-plugins.html) about setting
  up your editor.
- Start your editor from the root of this project via `esy vim` or `esy atom`
  etc. (Note VSCode has special `esy` support so that you don't need to start
  it this way from the command line).
- Add dependencies by adding entries to the `package.json`, running `esy
  install` then `esy build`.
