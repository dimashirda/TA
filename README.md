# TUGAS AKHIR

### Installation
   * Install tex-live
   
```
$ sudo apt-get update
$ sudo apt-get install texlive-full
```

   * Install tex-studio

   ```
   $ sudo apt-get install texstudio
   ```
   
   * You need to install windows fonts

   ```
   $ sudo apt-get install ttf-mscorefonts-installer
   $ sudo fc-cache -f -v
   ```

   * Open texstudio.
   * Open texstudio configuration in `option` menu
   * In tab `build`, choose `xelatex` as default compiler
   * Open tab `command`, set `xelatex -synctex=1 -interaction=nonstopmode --shell-escape %.tex` as xelatex command.
   * Install python-pygments
   
   ```
   $ sudo apt-get install python-pygments
   ```

   * Run `build & view` to compile.

   ```

## Note: If you have problem with section numbering (section number doesn't appear), run this command:

```
$ sudo wget http://mirrors.ctan.org/macros/latex/contrib/titlesec/titlesec.sty -O /usr/share/texlive/texmf-dist/tex/latex/titlesec/titlesec.sty
```