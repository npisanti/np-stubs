
Uses this ofxNanoVG
```
git clone https://github.com/galsasson/ofxNanoVG.git
```


Fixes to do to ofxNanoVG to make it work:

1) remove example folders form nvg and nsvg ( TODO: add exclude to `addon_config.mk` )

2) in `ofxNanoVG.h`

```cpp
#ifdef __ARM_ARCH
    #define NANOVG_GLES2_IMPLEMENTATION
#else 
    #define NANOVG_GL3_IMPLEMENTATION 
#endif
````

PS:

3) in `ofxNanoVG.cpp`, line 53 (little fix, non important for NANOVG_GL3_IMPLEMENTATION)
```cpp
#elif defined NANOVG_GL2_IMPLEMENTATION
```
