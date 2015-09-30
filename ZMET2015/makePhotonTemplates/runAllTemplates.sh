#! /bin/bash


source ../settings.sh

compile_looper
# create_analysis_output

if [ ! -d "../output/$analysis_version/" ]; then
	mkdir -p ../output/$analysis_version/
fi

# selection="_inclusive"
# ./makePhotonTemplates $selection $analysis_version data  &

selection="_rawMET"
./makePhotonTemplates $selection $analysis_version All_MC  &

# selection="_rawMET"
# ./makePhotonTemplates $selection $analysis_version data  &
# # ./runTemplateLooper $selection V07-04-03_goodtrigs zjets &
# # ./runTemplateLooper $selection V07-04-03_goodtrigs ttbar &
# # ./runTemplateLooper $selection V07-04-03_goodtrigs All_MC  &

# selection="_T1MET"
# ./makePhotonTemplates $selection $analysis_version data  &
# # ./runTemplateLooper $selection V07-04-03_goodtrigs zjets &
# # ./runTemplateLooper $selection V07-04-03_goodtrigs ttbar &
# # ./runTemplateLooper $selection V07-04-03_goodtrigs All_MC  &

