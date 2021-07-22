# Sky Engine
Sky Engine is an open-source, cross-platform 3D and 2D game engine based on OpenGL and Vulkan.

# Building from source:

## Getting the source:
### Clone through Git:
If you have Git installed, open the command prompt and run:
```
git clone https://github.com/JonasKorte/Sky-Engine.git
```

### Download zipped file:
#### 1.
Navigate to the [GitHub repository](https://github.com/JonasKorte/Sky-Engine) of this project.

#### 2.
Click on "Code" then "Download ZIP" or [download it directly](https://github.com/JonasKorte/Sky-Engine/archive/refs/heads/master.zip).

#### 3.
Extract the downloaded file.

## Building on Windows (Through Visual Studio):

### 1.
Run the command prompt as administrator and navigate to the directory where Sky Engine is either extracted or cloned.

### 2.
For Visual Studio 2015, run:
```
build.bat vs2015
```

For Visual Studio 2017, run:
```
build.bat vs2017
```

For Visual Studio 2019, run:
```
build.bat vs2019
```

### 3.
Double click the generated SkyEngine.sln file to open it in Visual Studio.

### 4.
In Visual Studio, go to the Configurations dropdown, and select "Dist".

### 5.
Go to the "Build" menu, and run "Build Solution" or press "F5".

### 6.
Done!

To clean the build files, run:
```
build.bat clean
```

## Building on Windows (Through msbuild):

### 1.
Run the command prompt as administrator and navigate to the directory where Sky Engine is either extracted or cloned.

### 2.
Locate your Visual Studio installation directory (the directory which has the folder "Common7" in it) and copy its path.

### 3.
Run:

```
build.bat vspath ~path~
```

Note: Replace \~path\~ with the Visual Studio path copied from step 2, wrapped in quotation marks.

### 4.
For Visual Studio 2015, run:
```
build.bat compile vs2015 Dist
```

For Visual Studio 2017, run:
```
build.bat compile vs2017 Dist
```

For Visual Studio 2019, run:
```
build.bat compile vs2019 Dist
```

### 5.
Done!

To clean the build files, run:
```
build.bat clean
```

## Building on Linux:

### 1.
Run the terminal and navigate to the directory where Sky Engine is either extracted or cloned.

### 2.
Run:
```
sudo sh build.sh gmake2 linux
```

### 3.
Run:
```
make
```
### 4.
Done!

To clean the build files, run:
```
sudo sh build.sh clean
```