add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
	PUBLIC FILE_SET headers TYPE HEADERS FILES
		QuadratureDecoder.hpp
	PRIVATE
		QuadratureDecoder.cpp
)

if(${PLATFORM} STREQUAL "native")
	# native platform (Windows, MacOS, Linux)
	target_sources(${PROJECT_NAME}
		PUBLIC FILE_SET platform_headers TYPE HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/native FILES
			native/coco/platform/QuadratureDecoder_Dummy.hpp
		PRIVATE
			native/coco/platform/QuadratureDecoder_Dummy.cpp
	)
elseif(${PLATFORM} STREQUAL "emu")
	# emulator platform with graphical user interface (Windows, MacOS, Linux)
	target_sources(${PROJECT_NAME}
		PUBLIC FILE_SET platform_headers TYPE HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/emu FILES
			emu/coco/platform/RotaryButton.hpp
			emu/coco/platform/RotaryButton_emu.hpp
			emu/coco/platform/RotaryKnob_emu.hpp
		PRIVATE
			emu/coco/platform/RotaryButton.cpp
			emu/coco/platform/RotaryButton_emu.cpp
			emu/coco/platform/RotaryKnob_emu.cpp
	)
elseif(${PLATFORM} MATCHES "^nrf52")
	target_sources(${PROJECT_NAME}
		PUBLIC FILE_SET platform_headers TYPE HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/nrf52 FILES
			nrf52/coco/platform/QuadratureDecoder_QDEC.hpp
		PRIVATE
			nrf52/coco/platform/QuadratureDecoder_QDEC.cpp
	)
elseif(${PLATFORM} MATCHES "^stm32f0")

endif()

target_link_libraries(${PROJECT_NAME}
	coco::coco
	coco-loop::coco-loop
	coco-io::coco-io
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		..
)

# install the library
install(TARGETS ${PROJECT_NAME}
	FILE_SET headers DESTINATION include/coco
	FILE_SET platform_headers DESTINATION include
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
