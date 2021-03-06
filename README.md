# lstm-compress
Data compression using LSTM. This project uses the same LSTM and preprocessing code as cmix (https://github.com/byronknoll/cmix). All of the other cmix models are removed, so the compression is performed using only LSTM.

lstm-compress is free software distributed under the GNU General Public License.

In Linux or OS X, use "make" to compile lstm-compress using g++. In Windows, lstm-compress can be compiled with MinGW (http://nuwen.net/mingw.html) or Cygwin (https://www.cygwin.com).

When running lstm-compress, it is usually recommended to enable preprocessing with "dictionary/english.dic".

lstm-compress can only compress/decompress single files. To compress multiple files or directories, create an archive file using "tar" (or some similar tool).

For some files, preprocessing using "precomp" may improve compression: https://github.com/schnaader/precomp-cpp
