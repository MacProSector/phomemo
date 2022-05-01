# Add libraries
add_library(
	phomemo_utility SHARED
	logger.cpp
)

# Set header targets
file(GLOB PHOMEMO_UTILITY_HEADERS "*.h" "*.hpp")

# Set library target properties
set_target_properties(
	phomemo_utility PROPERTIES
	PUBLIC_HEADER "${PHOMEMO_UTILITY_HEADERS}"
)

# Set installation targets
install(
	TARGETS phomemo_utility
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include/phomemo/utility
)