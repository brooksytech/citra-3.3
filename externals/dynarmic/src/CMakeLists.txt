add_library(dynarmic
    ../include/dynarmic/A32/a32.h
    ../include/dynarmic/A32/config.h
    ../include/dynarmic/A32/coprocessor.h
    ../include/dynarmic/A32/coprocessor_util.h
    ../include/dynarmic/A32/disassembler.h
    ../include/dynarmic/A64/a64.h
    ../include/dynarmic/A64/config.h
    ../include/dynarmic/A64/exclusive_monitor.h
    common/assert.cpp
    common/assert.h
    common/bit_util.h
    common/cast_util.h
    common/common_types.h
    common/crypto/aes.cpp
    common/crypto/aes.h
    common/crypto/crc32.cpp
    common/crypto/crc32.h
    common/crypto/sm4.cpp
    common/crypto/sm4.h
    common/fp/fpcr.h
    common/fp/fpsr.h
    common/fp/fused.cpp
    common/fp/fused.h
    common/fp/info.h
    common/fp/mantissa_util.h
    common/fp/op.h
    common/fp/op/FPCompare.cpp
    common/fp/op/FPCompare.h
    common/fp/op/FPConvert.cpp
    common/fp/op/FPConvert.h
    common/fp/op/FPMulAdd.cpp
    common/fp/op/FPMulAdd.h
    common/fp/op/FPNeg.h
    common/fp/op/FPRecipEstimate.cpp
    common/fp/op/FPRecipEstimate.h
    common/fp/op/FPRecipExponent.cpp
    common/fp/op/FPRecipExponent.h
    common/fp/op/FPRecipStepFused.cpp
    common/fp/op/FPRecipStepFused.h
    common/fp/op/FPRoundInt.cpp
    common/fp/op/FPRoundInt.h
    common/fp/op/FPRSqrtEstimate.cpp
    common/fp/op/FPRSqrtEstimate.h
    common/fp/op/FPRSqrtStepFused.cpp
    common/fp/op/FPRSqrtStepFused.h
    common/fp/op/FPToFixed.cpp
    common/fp/op/FPToFixed.h
    common/fp/process_exception.cpp
    common/fp/process_exception.h
    common/fp/process_nan.cpp
    common/fp/process_nan.h
    common/fp/rounding_mode.h
    common/fp/unpacked.cpp
    common/fp/unpacked.h
    common/fp/util.h
    common/intrusive_list.h
    common/iterator_util.h
    common/llvm_disassemble.cpp
    common/llvm_disassemble.h
    common/lut_from_list.h
    common/macro_util.h
    common/math_util.cpp
    common/math_util.h
    common/memory_pool.cpp
    common/memory_pool.h
    common/safe_ops.h
    common/scope_exit.h
    common/string_util.h
    common/u128.cpp
    common/u128.h
    common/variant_util.h
    frontend/A32/types.cpp
    frontend/A32/types.h
    frontend/A64/types.cpp
    frontend/A64/types.h
    frontend/decoder/decoder_detail.h
    frontend/decoder/matcher.h
    frontend/imm.cpp
    frontend/imm.h
    frontend/ir/basic_block.cpp
    frontend/ir/basic_block.h
    frontend/ir/cond.h
    frontend/ir/ir_emitter.cpp
    frontend/ir/ir_emitter.h
    frontend/ir/location_descriptor.cpp
    frontend/ir/location_descriptor.h
    frontend/ir/microinstruction.cpp
    frontend/ir/microinstruction.h
    frontend/ir/opcodes.cpp
    frontend/ir/opcodes.h
    frontend/ir/opcodes.inc
    frontend/ir/terminal.h
    frontend/ir/type.cpp
    frontend/ir/type.h
    frontend/ir/value.cpp
    frontend/ir/value.h
    ir_opt/constant_propagation_pass.cpp
    ir_opt/dead_code_elimination_pass.cpp
    ir_opt/identity_removal_pass.cpp
    ir_opt/ir_matcher.h
    ir_opt/passes.h
    ir_opt/verification_pass.cpp
)

if ("A32" IN_LIST DYNARMIC_FRONTENDS)
    target_sources(dynarmic PRIVATE
        frontend/A32/decoder/arm.h
        frontend/A32/decoder/arm.inc
        frontend/A32/decoder/asimd.h
        frontend/A32/decoder/asimd.inc
        frontend/A32/decoder/thumb16.h
        frontend/A32/decoder/thumb32.h
        frontend/A32/decoder/vfp.h
        frontend/A32/decoder/vfp.inc
        frontend/A32/disassembler/disassembler.h
        frontend/A32/disassembler/disassembler_arm.cpp
        frontend/A32/disassembler/disassembler_thumb.cpp
        frontend/A32/FPSCR.h
        frontend/A32/ir_emitter.cpp
        frontend/A32/ir_emitter.h
        frontend/A32/ITState.h
        frontend/A32/location_descriptor.cpp
        frontend/A32/location_descriptor.h
        frontend/A32/PSR.h
        frontend/A32/translate/impl/asimd_load_store_structures.cpp
        frontend/A32/translate/impl/asimd_one_reg_modified_immediate.cpp
        frontend/A32/translate/impl/asimd_three_same.cpp
        frontend/A32/translate/impl/asimd_two_regs_misc.cpp
        frontend/A32/translate/impl/barrier.cpp
        frontend/A32/translate/impl/branch.cpp
        frontend/A32/translate/impl/coprocessor.cpp
        frontend/A32/translate/impl/crc32.cpp
        frontend/A32/translate/impl/data_processing.cpp
        frontend/A32/translate/impl/divide.cpp
        frontend/A32/translate/impl/exception_generating.cpp
        frontend/A32/translate/impl/extension.cpp
        frontend/A32/translate/impl/hint.cpp
        frontend/A32/translate/impl/load_store.cpp
        frontend/A32/translate/impl/misc.cpp
        frontend/A32/translate/impl/multiply.cpp
        frontend/A32/translate/impl/packing.cpp
        frontend/A32/translate/impl/parallel.cpp
        frontend/A32/translate/impl/reversal.cpp
        frontend/A32/translate/impl/saturated.cpp
        frontend/A32/translate/impl/status_register_access.cpp
        frontend/A32/translate/impl/synchronization.cpp
        frontend/A32/translate/impl/thumb16.cpp
        frontend/A32/translate/impl/thumb32.cpp
        frontend/A32/translate/impl/translate_arm.h
        frontend/A32/translate/impl/translate_thumb.h
        frontend/A32/translate/impl/vfp.cpp
        frontend/A32/translate/translate.cpp
        frontend/A32/translate/translate.h
        frontend/A32/translate/translate_arm.cpp
        frontend/A32/translate/translate_thumb.cpp
        ir_opt/a32_constant_memory_reads_pass.cpp
        ir_opt/a32_get_set_elimination_pass.cpp
        ir_opt/a32_merge_interpret_blocks.cpp
    )
endif()

if ("A64" IN_LIST DYNARMIC_FRONTENDS)
    target_sources(dynarmic PRIVATE
        frontend/A64/decoder/a64.h
        frontend/A64/decoder/a64.inc
        frontend/A64/ir_emitter.cpp
        frontend/A64/ir_emitter.h
        frontend/A64/location_descriptor.cpp
        frontend/A64/location_descriptor.h
        frontend/A64/translate/impl/branch.cpp
        frontend/A64/translate/impl/data_processing_addsub.cpp
        frontend/A64/translate/impl/data_processing_bitfield.cpp
        frontend/A64/translate/impl/data_processing_conditional_compare.cpp
        frontend/A64/translate/impl/data_processing_conditional_select.cpp
        frontend/A64/translate/impl/data_processing_crc32.cpp
        frontend/A64/translate/impl/data_processing_logical.cpp
        frontend/A64/translate/impl/data_processing_multiply.cpp
        frontend/A64/translate/impl/data_processing_pcrel.cpp
        frontend/A64/translate/impl/data_processing_register.cpp
        frontend/A64/translate/impl/data_processing_shift.cpp
        frontend/A64/translate/impl/exception_generating.cpp
        frontend/A64/translate/impl/floating_point_compare.cpp
        frontend/A64/translate/impl/floating_point_conditional_compare.cpp
        frontend/A64/translate/impl/floating_point_conditional_select.cpp
        frontend/A64/translate/impl/floating_point_conversion_fixed_point.cpp
        frontend/A64/translate/impl/floating_point_conversion_integer.cpp
        frontend/A64/translate/impl/floating_point_data_processing_one_register.cpp
        frontend/A64/translate/impl/floating_point_data_processing_three_register.cpp
        frontend/A64/translate/impl/floating_point_data_processing_two_register.cpp
        frontend/A64/translate/impl/impl.cpp
        frontend/A64/translate/impl/impl.h
        frontend/A64/translate/impl/load_store_exclusive.cpp
        frontend/A64/translate/impl/load_store_load_literal.cpp
        frontend/A64/translate/impl/load_store_multiple_structures.cpp
        frontend/A64/translate/impl/load_store_no_allocate_pair.cpp
        frontend/A64/translate/impl/load_store_register_immediate.cpp
        frontend/A64/translate/impl/load_store_register_pair.cpp
        frontend/A64/translate/impl/load_store_register_register_offset.cpp
        frontend/A64/translate/impl/load_store_register_unprivileged.cpp
        frontend/A64/translate/impl/load_store_single_structure.cpp
        frontend/A64/translate/impl/move_wide.cpp
        frontend/A64/translate/impl/simd_across_lanes.cpp
        frontend/A64/translate/impl/simd_aes.cpp
        frontend/A64/translate/impl/simd_copy.cpp
        frontend/A64/translate/impl/simd_crypto_four_register.cpp
        frontend/A64/translate/impl/simd_crypto_three_register.cpp
        frontend/A64/translate/impl/simd_extract.cpp
        frontend/A64/translate/impl/simd_modified_immediate.cpp
        frontend/A64/translate/impl/simd_permute.cpp
        frontend/A64/translate/impl/simd_scalar_pairwise.cpp
        frontend/A64/translate/impl/simd_scalar_shift_by_immediate.cpp
        frontend/A64/translate/impl/simd_scalar_three_same.cpp
        frontend/A64/translate/impl/simd_scalar_two_register_misc.cpp
        frontend/A64/translate/impl/simd_scalar_x_indexed_element.cpp
        frontend/A64/translate/impl/simd_sha.cpp
        frontend/A64/translate/impl/simd_sha512.cpp
        frontend/A64/translate/impl/simd_shift_by_immediate.cpp
        frontend/A64/translate/impl/simd_table_lookup.cpp
        frontend/A64/translate/impl/simd_three_different.cpp
        frontend/A64/translate/impl/simd_three_same.cpp
        frontend/A64/translate/impl/simd_three_same_extra.cpp
        frontend/A64/translate/impl/simd_two_register_misc.cpp
        frontend/A64/translate/impl/simd_vector_x_indexed_element.cpp
        frontend/A64/translate/impl/sys_dc.cpp
        frontend/A64/translate/impl/system.cpp
        frontend/A64/translate/impl/system_flag_format.cpp
        frontend/A64/translate/impl/system_flag_manipulation.cpp
        frontend/A64/translate/translate.cpp
        frontend/A64/translate/translate.h
        ir_opt/a64_callback_config_pass.cpp
        ir_opt/a64_get_set_elimination_pass.cpp
        ir_opt/a64_merge_interpret_blocks.cpp
    )
endif()

if (ARCHITECTURE_x86_64)
    target_sources(dynarmic PRIVATE
        backend/x64/abi.cpp
        backend/x64/abi.h
        backend/x64/block_of_code.cpp
        backend/x64/block_of_code.h
        backend/x64/block_range_information.cpp
        backend/x64/block_range_information.h
        backend/x64/callback.cpp
        backend/x64/callback.h
        backend/x64/constant_pool.cpp
        backend/x64/constant_pool.h
        backend/x64/devirtualize.h
        backend/x64/emit_x64.cpp
        backend/x64/emit_x64.h
        backend/x64/emit_x64_aes.cpp
        backend/x64/emit_x64_crc32.cpp
        backend/x64/emit_x64_data_processing.cpp
        backend/x64/emit_x64_floating_point.cpp
        backend/x64/emit_x64_packed.cpp
        backend/x64/emit_x64_saturation.cpp
        backend/x64/emit_x64_sm4.cpp
        backend/x64/emit_x64_vector.cpp
        backend/x64/emit_x64_vector_floating_point.cpp
        backend/x64/emit_x64_vector_saturation.cpp
        backend/x64/exception_handler.h
        backend/x64/hostloc.cpp
        backend/x64/hostloc.h
        backend/x64/jitstate_info.h
        backend/x64/oparg.h
        backend/x64/perf_map.cpp
        backend/x64/perf_map.h
        backend/x64/reg_alloc.cpp
        backend/x64/reg_alloc.h
    )

    if ("A32" IN_LIST DYNARMIC_FRONTENDS)
        target_sources(dynarmic PRIVATE
            backend/x64/a32_emit_x64.cpp
            backend/x64/a32_emit_x64.h
            backend/x64/a32_interface.cpp
            backend/x64/a32_jitstate.cpp
            backend/x64/a32_jitstate.h
        )
    endif()

    if ("A64" IN_LIST DYNARMIC_FRONTENDS)
        target_sources(dynarmic PRIVATE
            backend/x64/a64_emit_x64.cpp
            backend/x64/a64_emit_x64.h
            backend/x64/a64_exclusive_monitor.cpp
            backend/x64/a64_interface.cpp
            backend/x64/a64_jitstate.cpp
            backend/x64/a64_jitstate.h
        )
    endif()

    if (WIN32)
        target_sources(dynarmic PRIVATE backend/x64/exception_handler_windows.cpp)
    elseif (APPLE)
        find_path(MACH_EXC_DEFS_DIR "mach/mach_exc.defs")
        if (NOT MACH_EXC_DEFS_DIR)
            message(WARNING "macOS fastmem disabled: unable to find mach/mach_exc.defs")
            target_sources(dynarmic PRIVATE backend/x64/exception_handler_generic.cpp)
        else()
            message(STATUS "mach/mach_exc.defs location: ${MACH_EXC_DEFS_DIR}")
            execute_process(
                COMMAND
                    mkdir -p "${CMAKE_CURRENT_SOURCE_DIR}/backend/x64/mig"
                COMMAND
                    mig
                    -arch x86_64
                    -user "${CMAKE_CURRENT_SOURCE_DIR}/backend/x64/mig/mach_exc_user.c"
                    -header "${CMAKE_CURRENT_SOURCE_DIR}/backend/x64/mig/mach_exc_user.h"
                    -server "${CMAKE_CURRENT_SOURCE_DIR}/backend/x64/mig/mach_exc_server.c"
                    -sheader "${CMAKE_CURRENT_SOURCE_DIR}/backend/x64/mig/mach_exc_server.h"
                    "${MACH_EXC_DEFS_DIR}/mach/mach_exc.defs"
            )
            target_sources(dynarmic PRIVATE
                backend/x64/exception_handler_macos.cpp
                backend/x64/mig/mach_exc_server.c
                backend/x64/mig/mach_exc_server.h
            )
        endif()
    elseif (UNIX)
        if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
            target_link_libraries(dynarmic PUBLIC rt)
        endif()
        target_sources(dynarmic PRIVATE backend/x64/exception_handler_posix.cpp)
    else()
        target_sources(dynarmic PRIVATE backend/x64/exception_handler_generic.cpp)
    endif()

    target_link_libraries(dynarmic PRIVATE xbyak)
elseif(ARCHITECTURE_Aarch64)
    target_sources(dynarmic PRIVATE
         backend/A64/emitter/a64_emitter.cpp
         backend/A64/emitter/a64_emitter.h
         backend/A64/emitter/arm_common.h
         backend/A64/emitter/code_block.h
         # backend/A64/a64_emit_a64.cpp
         # backend/A64/a64_emit_a64.h
         # backend/A64/a64_exclusive_monitor.cpp
         # backend/A64/a64_interface.cpp
         # backend/A64/a64_jitstate.cpp
         # backend/A64/a64_jitstate.h
         backend/A64/abi.cpp
         backend/A64/abi.h
         backend/A64/block_of_code.cpp
         backend/A64/block_of_code.h
         backend/A64/block_range_information.cpp
         backend/A64/block_range_information.h
         backend/A64/callback.cpp
         backend/A64/callback.h
         backend/A64/constant_pool.cpp
         backend/A64/constant_pool.h
         backend/A64/devirtualize.h
         backend/A64/emit_a64.cpp
         backend/A64/emit_a64.h
         # backend/A64/emit_a64_aes.cpp
         # backend/A64/emit_a64_crc32.cpp
         backend/A64/emit_a64_data_processing.cpp
         backend/A64/emit_a64_floating_point.cpp
         backend/A64/emit_a64_packed.cpp
         backend/A64/emit_a64_saturation.cpp
         # backend/A64/emit_a64_sm4.cpp
         # backend/A64/emit_a64_vector.cpp
         # backend/A64/emit_a64_vector_floating_point.cpp         
         backend/A64/exception_handler.h
         backend/A64/hostloc.cpp
         backend/A64/hostloc.h
         backend/A64/jitstate_info.h
         backend/A64/opcodes.inc
         backend/A64/perf_map.cpp
         backend/A64/perf_map.h
         backend/A64/reg_alloc.cpp
         backend/A64/reg_alloc.h
    )
    
    if ("A32" IN_LIST DYNARMIC_FRONTENDS)
        target_sources(dynarmic PRIVATE
            backend/A64/a32_emit_a64.cpp
            backend/A64/a32_emit_a64.h
            backend/A64/a32_interface.cpp
            backend/A64/a32_jitstate.cpp
            backend/A64/a32_jitstate.h
        )
    endif()
    
    if (UNIX)
        target_sources(dynarmic PRIVATE backend/A64/exception_handler_posix.cpp)
    else()
        target_sources(dynarmic PRIVATE backend/A64/exception_handler_generic.cpp)
    endif()
else()
    message(FATAL_ERROR "Unsupported architecture")
endif()

include(CreateDirectoryGroups)
create_target_directory_groups(dynarmic)

target_include_directories(dynarmic
                           PUBLIC ../include
                           PRIVATE .)
target_compile_options(dynarmic PRIVATE ${DYNARMIC_CXX_FLAGS})
target_link_libraries(dynarmic
    PRIVATE
        boost
        fmt::fmt
        mp
        tsl::robin_map
        $<$<BOOL:DYNARMIC_USE_LLVM>:${llvm_libs}>
)

if(ANDROID)
    target_link_libraries(dynarmic PRIVATE log)
endif()
if (DYNARMIC_ENABLE_CPU_FEATURE_DETECTION)
    target_compile_definitions(dynarmic PRIVATE DYNARMIC_ENABLE_CPU_FEATURE_DETECTION=1)
endif()
if (DYNARMIC_ENABLE_NO_EXECUTE_SUPPORT)
    target_compile_definitions(dynarmic PRIVATE DYNARMIC_ENABLE_NO_EXECUTE_SUPPORT=1)
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(dynarmic PRIVATE FMT_USE_WINDOWS_H=0)
endif()
# Disable this as it relies on a non-standard feature
target_compile_definitions(dynarmic PRIVATE FMT_USE_USER_DEFINED_LITERALS=0)
