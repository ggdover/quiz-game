##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Text-Quiz
ConfigurationName      :=Debug
WorkspacePath          := "/home/viktor/Documents/codelite"
ProjectPath            := "/home/viktor/Documents/codelite/Text-Quiz"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=12/07/15
CodeLitePath           :="/home/viktor/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Text-Quiz.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/viktor.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/menu_Alfred.c$(ObjectSuffix) $(IntermediateDirectory)/filip.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/viktor.c$(ObjectSuffix): viktor.c $(IntermediateDirectory)/viktor.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/viktor/Documents/codelite/Text-Quiz/viktor.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/viktor.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/viktor.c$(DependSuffix): viktor.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/viktor.c$(ObjectSuffix) -MF$(IntermediateDirectory)/viktor.c$(DependSuffix) -MM "viktor.c"

$(IntermediateDirectory)/viktor.c$(PreprocessSuffix): viktor.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/viktor.c$(PreprocessSuffix) "viktor.c"

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/viktor/Documents/codelite/Text-Quiz/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/menu_Alfred.c$(ObjectSuffix): Projekt_intro_progr_menu/menu/Alfred.c $(IntermediateDirectory)/menu_Alfred.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/viktor/Documents/codelite/Text-Quiz/Projekt_intro_progr_menu/menu/Alfred.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menu_Alfred.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/menu_Alfred.c$(DependSuffix): Projekt_intro_progr_menu/menu/Alfred.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/menu_Alfred.c$(ObjectSuffix) -MF$(IntermediateDirectory)/menu_Alfred.c$(DependSuffix) -MM "Projekt_intro_progr_menu/menu/Alfred.c"

$(IntermediateDirectory)/menu_Alfred.c$(PreprocessSuffix): Projekt_intro_progr_menu/menu/Alfred.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/menu_Alfred.c$(PreprocessSuffix) "Projekt_intro_progr_menu/menu/Alfred.c"

$(IntermediateDirectory)/filip.c$(ObjectSuffix): filip.c $(IntermediateDirectory)/filip.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/viktor/Documents/codelite/Text-Quiz/filip.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/filip.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/filip.c$(DependSuffix): filip.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/filip.c$(ObjectSuffix) -MF$(IntermediateDirectory)/filip.c$(DependSuffix) -MM "filip.c"

$(IntermediateDirectory)/filip.c$(PreprocessSuffix): filip.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/filip.c$(PreprocessSuffix) "filip.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/

