# QtQuestions
Qt API questions arising from learning Qt

## Qt6 Webassembly

Requires additional linker flag
```
-D CMAKE_EXE_LINKER_FLAGS="-s EXPORT_NAME=hca_entry"
```