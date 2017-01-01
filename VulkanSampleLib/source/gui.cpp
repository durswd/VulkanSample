﻿#include <vsl/gui.h>
#include <vsl/application.h>
#include <vsl/buffer.h>
#include <glm/glm.hpp>


namespace vsl
{
	namespace
	{
		static const uint8_t kGuiVS[] =
		{
			0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x08, 0x00,
			0x6c, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 0x00,
			0x11, 0x00, 0x02, 0x00, 0x21, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64,
			0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x0a, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x1f, 0x16, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e,
			0x00, 0x00, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x41, 0x14, 0x00, 0x00,
			0x6a, 0x16, 0x00, 0x00, 0x42, 0x13, 0x00, 0x00, 0x80, 0x14, 0x00, 0x00,
			0x47, 0x00, 0x03, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
			0x47, 0x00, 0x04, 0x00, 0x41, 0x14, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
			0x02, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x6a, 0x16, 0x00, 0x00,
			0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00,
			0xb1, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0xb1, 0x02, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x48, 0x00, 0x05, 0x00, 0xb1, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
			0x0b, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00,
			0xb1, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
			0x04, 0x00, 0x00, 0x00, 0x47, 0x00, 0x03, 0x00, 0xb1, 0x02, 0x00, 0x00,
			0x02, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x80, 0x14, 0x00, 0x00,
			0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00,
			0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x06, 0x04, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
			0x47, 0x00, 0x03, 0x00, 0x06, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
			0x47, 0x00, 0x04, 0x00, 0xfa, 0x16, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00,
			0x21, 0x00, 0x03, 0x00, 0x02, 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
			0x16, 0x00, 0x03, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
			0x17, 0x00, 0x04, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00,
			0x04, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00,
			0x0d, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x04, 0x00,
			0x1a, 0x04, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
			0x20, 0x00, 0x04, 0x00, 0x97, 0x06, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x1a, 0x04, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x97, 0x06, 0x00, 0x00,
			0x47, 0x11, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00,
			0x0c, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0b, 0x0a, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x9a, 0x02, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
			0x9a, 0x02, 0x00, 0x00, 0x41, 0x14, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x20, 0x00, 0x04, 0x00, 0x9b, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x1d, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
			0x0e, 0x0a, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
			0x90, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
			0x3b, 0x00, 0x04, 0x00, 0x90, 0x02, 0x00, 0x00, 0x6a, 0x16, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x91, 0x02, 0x00, 0x00,
			0x03, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00,
			0x0b, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x2b, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x04, 0x00, 0x7f, 0x02, 0x00, 0x00,
			0x0d, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x1e, 0x00, 0x06, 0x00,
			0xb1, 0x02, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00,
			0x7f, 0x02, 0x00, 0x00, 0x7f, 0x02, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
			0x2e, 0x05, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xb1, 0x02, 0x00, 0x00,
			0x3b, 0x00, 0x04, 0x00, 0x2e, 0x05, 0x00, 0x00, 0x42, 0x13, 0x00, 0x00,
			0x03, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x90, 0x02, 0x00, 0x00,
			0x80, 0x14, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x04, 0x00,
			0x06, 0x04, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
			0x20, 0x00, 0x04, 0x00, 0x83, 0x06, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
			0x06, 0x04, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x83, 0x06, 0x00, 0x00,
			0xfa, 0x16, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
			0x92, 0x02, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
			0x2b, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0c, 0x0a, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00,
			0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x36, 0x00, 0x05, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x1f, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x02, 0x05, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x6b, 0x60, 0x00, 0x00,
			0x3d, 0x00, 0x04, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x71, 0x4e, 0x00, 0x00,
			0x41, 0x14, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x9b, 0x02, 0x00, 0x00,
			0xaa, 0x26, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x0b, 0x0a, 0x00, 0x00,
			0x3e, 0x00, 0x03, 0x00, 0xaa, 0x26, 0x00, 0x00, 0x71, 0x4e, 0x00, 0x00,
			0x3d, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0xda, 0x35, 0x00, 0x00,
			0x6a, 0x16, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x91, 0x02, 0x00, 0x00,
			0xea, 0x50, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x0e, 0x0a, 0x00, 0x00,
			0x3e, 0x00, 0x03, 0x00, 0xea, 0x50, 0x00, 0x00, 0xda, 0x35, 0x00, 0x00,
			0x3d, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0xc7, 0x35, 0x00, 0x00,
			0x80, 0x14, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x92, 0x02, 0x00, 0x00,
			0xef, 0x56, 0x00, 0x00, 0xfa, 0x16, 0x00, 0x00, 0x0b, 0x0a, 0x00, 0x00,
			0x3d, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0xe0, 0x29, 0x00, 0x00,
			0xef, 0x56, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x13, 0x00, 0x00, 0x00,
			0xa0, 0x22, 0x00, 0x00, 0xc7, 0x35, 0x00, 0x00, 0xe0, 0x29, 0x00, 0x00,
			0x41, 0x00, 0x05, 0x00, 0x92, 0x02, 0x00, 0x00, 0x42, 0x2c, 0x00, 0x00,
			0xfa, 0x16, 0x00, 0x00, 0x0e, 0x0a, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
			0x13, 0x00, 0x00, 0x00, 0x09, 0x60, 0x00, 0x00, 0x42, 0x2c, 0x00, 0x00,
			0x81, 0x00, 0x05, 0x00, 0x13, 0x00, 0x00, 0x00, 0xd1, 0x4e, 0x00, 0x00,
			0xa0, 0x22, 0x00, 0x00, 0x09, 0x60, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00,
			0x0d, 0x00, 0x00, 0x00, 0xa1, 0x41, 0x00, 0x00, 0xd1, 0x4e, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00,
			0x84, 0x36, 0x00, 0x00, 0xd1, 0x4e, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x50, 0x00, 0x07, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x54, 0x47, 0x00, 0x00,
			0xa1, 0x41, 0x00, 0x00, 0x84, 0x36, 0x00, 0x00, 0x0c, 0x0a, 0x00, 0x00,
			0x8a, 0x00, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x9b, 0x02, 0x00, 0x00,
			0x17, 0x2f, 0x00, 0x00, 0x42, 0x13, 0x00, 0x00, 0x0b, 0x0a, 0x00, 0x00,
			0x3e, 0x00, 0x03, 0x00, 0x17, 0x2f, 0x00, 0x00, 0x54, 0x47, 0x00, 0x00,
			0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00
		};

		static const uint8_t kGuiPS[] =
		{
			0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x08, 0x00,
			0x6c, 0x5d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30,
			0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x00,
			0x1f, 0x16, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
			0x7a, 0x0c, 0x00, 0x00, 0x35, 0x16, 0x00, 0x00, 0x10, 0x00, 0x03, 0x00,
			0x1f, 0x16, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
			0x7a, 0x0c, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x47, 0x00, 0x04, 0x00, 0x7a, 0x0c, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x03, 0x00, 0x1a, 0x04, 0x00, 0x00,
			0x02, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0xec, 0x14, 0x00, 0x00,
			0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
			0xec, 0x14, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x13, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00,
			0x02, 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00,
			0x0d, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00,
			0x1d, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
			0x20, 0x00, 0x04, 0x00, 0x9a, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x1d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x9a, 0x02, 0x00, 0x00,
			0x7a, 0x0c, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00,
			0x13, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
			0x1e, 0x00, 0x04, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00,
			0x13, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x97, 0x06, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
			0x97, 0x06, 0x00, 0x00, 0x35, 0x16, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x15, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
			0x0b, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
			0x9b, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00,
			0x19, 0x00, 0x09, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x1b, 0x00, 0x03, 0x00, 0xfe, 0x01, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00,
			0x20, 0x00, 0x04, 0x00, 0x7b, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0xfe, 0x01, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x7b, 0x04, 0x00, 0x00,
			0xec, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
			0x0c, 0x00, 0x00, 0x00, 0x0e, 0x0a, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x20, 0x00, 0x04, 0x00, 0x90, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x13, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x08, 0x00, 0x00, 0x00,
			0x1f, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00,
			0xf8, 0x00, 0x02, 0x00, 0x6b, 0x5d, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00,
			0x9b, 0x02, 0x00, 0x00, 0x8d, 0x1b, 0x00, 0x00, 0x35, 0x16, 0x00, 0x00,
			0x0b, 0x0a, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x1d, 0x00, 0x00, 0x00,
			0x0b, 0x40, 0x00, 0x00, 0x8d, 0x1b, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
			0xfe, 0x01, 0x00, 0x00, 0xc0, 0x36, 0x00, 0x00, 0xec, 0x14, 0x00, 0x00,
			0x41, 0x00, 0x05, 0x00, 0x90, 0x02, 0x00, 0x00, 0xc2, 0x43, 0x00, 0x00,
			0x35, 0x16, 0x00, 0x00, 0x0e, 0x0a, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
			0x13, 0x00, 0x00, 0x00, 0x02, 0x4e, 0x00, 0x00, 0xc2, 0x43, 0x00, 0x00,
			0x57, 0x00, 0x05, 0x00, 0x1d, 0x00, 0x00, 0x00, 0xb9, 0x46, 0x00, 0x00,
			0xc0, 0x36, 0x00, 0x00, 0x02, 0x4e, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00,
			0x1d, 0x00, 0x00, 0x00, 0xe4, 0x23, 0x00, 0x00, 0x0b, 0x40, 0x00, 0x00,
			0xb9, 0x46, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x7a, 0x0c, 0x00, 0x00,
			0xe4, 0x23, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00
		};

		struct VertexUniform
		{
			float	scale_[2];
			float	translate_[2];
		};	// struct VertexUniform

		struct ImDrawVertex
		{
			glm::vec2	pos_;
			glm::vec2	uv_;
			uint32_t	color_;
		};	// struct ImDrawVertex

	}	// namespace


	Gui* Gui::guiHandle_ = nullptr;

	//----
	// 初期化
	bool Gui::Initialize(Device& owner, Image& renderTarget, Image* pDepthTarget)
	{
		vk::Format rtFormat = renderTarget.GetFormat();
		bool ret = true;
		if (pDepthTarget)
		{
			vk::Format depthFormat = pDepthTarget->GetFormat();
			ret = Initialize(owner, rtFormat, depthFormat);
		}
		else
		{
			ret = Initialize(owner, rtFormat, nullptr);
		}
		return ret;
	}
	bool Gui::Initialize(Device& owner, vk::ArrayProxy<vk::Format> colorFormats, vk::Optional<vk::Format> depthFormat)
	{
		if (guiHandle_)
		{
			return false;
		}

		pOwner_ = &owner;
		guiHandle_ = this;

		nonCoherentAtomSize_ = owner.GetPhysicalDevice().getProperties().limits.nonCoherentAtomSize;

		// コールバックの登録
		ImGuiIO& io = ImGui::GetIO();

		io.RenderDrawListsFn = &Gui::RenderDrawList;

		// 描画パス作成
		{
			if (!renderPass_.InitializeAsColorStandard(owner, colorFormats, depthFormat))
			{
				return false;
			}
		}

		// シェーダ生成
		{
			bool ret = true;
			ret = ret && vshader_.CreateFromMemory(owner, kGuiVS, sizeof(kGuiVS));
			ret = ret && pshader_.CreateFromMemory(owner, kGuiPS, sizeof(kGuiPS));
			if (!ret)
			{
				return false;
			}
		}

		// サンプラ
		{
			vk::SamplerCreateInfo samplerCreateInfo;
			samplerCreateInfo.magFilter = vk::Filter::eLinear;
			samplerCreateInfo.minFilter = vk::Filter::eLinear;
			samplerCreateInfo.mipmapMode = vk::SamplerMipmapMode::eLinear;
			samplerCreateInfo.addressModeU = vk::SamplerAddressMode::eRepeat;
			samplerCreateInfo.addressModeV = vk::SamplerAddressMode::eRepeat;
			samplerCreateInfo.addressModeW = vk::SamplerAddressMode::eRepeat;
			samplerCreateInfo.mipLodBias = 0.0f;
			samplerCreateInfo.compareOp = vk::CompareOp::eNever;
			samplerCreateInfo.minLod = -1000.0f;
			samplerCreateInfo.maxLod = 1000.0f;
			samplerCreateInfo.maxAnisotropy = 8;
			samplerCreateInfo.anisotropyEnable = VK_TRUE;
			samplerCreateInfo.borderColor = vk::BorderColor::eFloatOpaqueWhite;
			fontSampler_ = owner.GetDevice().createSampler(samplerCreateInfo);
		}

		// DescriptorSet
		{
			// Layout
			{
				// 描画時のシェーダセットに対するデスクリプタセットのレイアウトを指定する
				std::array<vk::DescriptorSetLayoutBinding, 1> layoutBindings;
				// CombinedImageSampler for PixelShader
				layoutBindings[0].descriptorType = vk::DescriptorType::eCombinedImageSampler;
				layoutBindings[0].descriptorCount = 1;
				layoutBindings[0].binding = 0;
				layoutBindings[0].stageFlags = vk::ShaderStageFlagBits::eFragment;
				layoutBindings[0].pImmutableSamplers = &fontSampler_;

				// レイアウトを生成
				vk::DescriptorSetLayoutCreateInfo info;
				info.bindingCount = static_cast<uint32_t>(layoutBindings.size());
				info.pBindings = layoutBindings.data();
				descSetLayout_ = owner.GetDevice().createDescriptorSetLayout(info, nullptr);
				if (!descSetLayout_)
				{
					return false;
				}
			}

			// Pool
			{
				std::array<vk::DescriptorPoolSize, 1> typeCounts;
				typeCounts[0].type = vk::DescriptorType::eCombinedImageSampler;
				typeCounts[0].descriptorCount = 1;

				// デスクリプタプールを生成
				vk::DescriptorPoolCreateInfo info;
				info.poolSizeCount = static_cast<uint32_t>(typeCounts.size());
				info.pPoolSizes = typeCounts.data();
				info.maxSets = 1;
				descPool_ = owner.GetDevice().createDescriptorPool(info);
				if (!descPool_)
				{
					return false;
				}
			}

			// Set
			{
				vk::DescriptorSetAllocateInfo allocInfo;
				allocInfo.descriptorPool = descPool_;
				allocInfo.descriptorSetCount = 1;
				allocInfo.pSetLayouts = &descSetLayout_;
				descSet_ = owner.GetDevice().allocateDescriptorSets(allocInfo)[0];
				if (!descSet_)
				{
					return false;
				}
			}
		}

		// Pipeline
		{
			// Layout
			{
				// PushConstant
				vk::PushConstantRange pushConstantRange(vk::ShaderStageFlagBits::eVertex, 0, sizeof(VertexUniform));

				vk::PipelineLayoutCreateInfo info;
				info.setLayoutCount = 1;
				info.pSetLayouts = &descSetLayout_;
				info.pushConstantRangeCount = 1;
				info.pPushConstantRanges = &pushConstantRange;
				pipelineLayout_ = owner.GetDevice().createPipelineLayout(info);
			}

			// Pipeline
			{
				vk::PipelineInputAssemblyStateCreateInfo iaInfo(
					vk::PipelineInputAssemblyStateCreateFlags(),
					vk::PrimitiveTopology::eTriangleList);

				vk::PipelineRasterizationStateCreateInfo rsInfo(
					vk::PipelineRasterizationStateCreateFlags(),
					0, 0, vk::PolygonMode::eFill,
					vk::CullModeFlagBits::eNone, vk::FrontFace::eCounterClockwise,
					0, 0.0f, 0.0f, 0.0f, 1.0f);

				vk::PipelineColorBlendAttachmentState blendAttachmentState(
					VK_TRUE, vk::BlendFactor::eSrcAlpha, vk::BlendFactor::eOneMinusSrcAlpha, vk::BlendOp::eAdd,
					vk::BlendFactor::eOneMinusSrcAlpha, vk::BlendFactor::eZero, vk::BlendOp::eAdd,
					vk::ColorComponentFlagBits::eR | vk::ColorComponentFlagBits::eG | vk::ColorComponentFlagBits::eB | vk::ColorComponentFlagBits::eA);
				vk::PipelineColorBlendStateCreateInfo blendInfo(
					vk::PipelineColorBlendStateCreateFlags(), 0, vk::LogicOp::eClear, 1, &blendAttachmentState);

				vk::PipelineViewportStateCreateInfo viewportInfo(vk::PipelineViewportStateCreateFlags(), 1, nullptr, 1, nullptr);

				vk::DynamicState dynamicStates[] = { vk::DynamicState::eViewport, vk::DynamicState::eScissor };
				vk::PipelineDynamicStateCreateInfo dynamicInfo(vk::PipelineDynamicStateCreateFlags(), ARRAYSIZE(dynamicStates), dynamicStates);

				vk::PipelineDepthStencilStateCreateInfo dsInfo;

				vk::PipelineMultisampleStateCreateInfo msInfo;
				msInfo.pSampleMask = nullptr;
				msInfo.rasterizationSamples = vk::SampleCountFlagBits::e1;

				std::array<vk::VertexInputBindingDescription, 1> bindDescs;
				bindDescs[0].binding = 0;		// 0番へバインド
				bindDescs[0].stride = sizeof(ImDrawVertex);
				bindDescs[0].inputRate = vk::VertexInputRate::eVertex;

				std::array<vk::VertexInputAttributeDescription, 3> attribDescs;
				// Position
				attribDescs[0].binding = 0;
				attribDescs[0].location = 0;
				attribDescs[0].format = vk::Format::eR32G32Sfloat;
				attribDescs[0].offset = 0;
				// UV
				attribDescs[1].binding = 0;
				attribDescs[1].location = 1;
				attribDescs[1].format = vk::Format::eR32G32Sfloat;
				attribDescs[1].offset = sizeof(glm::vec2);
				// Color
				attribDescs[2].binding = 0;
				attribDescs[2].location = 2;
				attribDescs[2].format = vk::Format::eR8G8B8A8Unorm;
				attribDescs[2].offset = attribDescs[1].offset + sizeof(glm::vec2);

				vk::PipelineVertexInputStateCreateInfo vinputState;
				vinputState.vertexBindingDescriptionCount = static_cast<uint32_t>(bindDescs.size());
				vinputState.pVertexBindingDescriptions = bindDescs.data();
				vinputState.vertexAttributeDescriptionCount = static_cast<uint32_t>(attribDescs.size());
				vinputState.pVertexAttributeDescriptions = attribDescs.data();

				std::array<vk::PipelineShaderStageCreateInfo, 2> shaderStages;
				shaderStages[0].stage = vk::ShaderStageFlagBits::eVertex;
				shaderStages[0].module = vshader_.GetModule();
				shaderStages[0].pName = "main";
				shaderStages[1].stage = vk::ShaderStageFlagBits::eFragment;
				shaderStages[1].module = pshader_.GetModule();
				shaderStages[1].pName = "main";

				vk::GraphicsPipelineCreateInfo pipelineCreateInfo;
				pipelineCreateInfo.layout = pipelineLayout_;
				pipelineCreateInfo.renderPass = renderPass_.GetPass();
				pipelineCreateInfo.stageCount = static_cast<uint32_t>(shaderStages.size());
				pipelineCreateInfo.pStages = shaderStages.data();
				pipelineCreateInfo.pVertexInputState = &vinputState;
				pipelineCreateInfo.pInputAssemblyState = &iaInfo;
				pipelineCreateInfo.pRasterizationState = &rsInfo;
				pipelineCreateInfo.pColorBlendState = &blendInfo;
				pipelineCreateInfo.pMultisampleState = &msInfo;
				pipelineCreateInfo.pViewportState = &viewportInfo;
				pipelineCreateInfo.pDepthStencilState = &dsInfo;
				pipelineCreateInfo.pDynamicState = &dynamicInfo;

				pipeline_ = owner.GetDevice().createGraphicsPipelines(owner.GetPipelineCache(), pipelineCreateInfo, nullptr)[0];
				if (!pipeline_)
				{
					return false;
				}
			}
		}

		// 頂点・インデックスバッファを作成
		uint32_t frameCount = owner.GetSwapchain().GetImageCount();
		vertexBuffers_ = new vsl::Buffer[frameCount];
		indexBuffers_ = new vsl::Buffer[frameCount];

		return true;
	}

	//----
	// 破棄
	void Gui::Destroy()
	{
		if (pOwner_)
		{
			vk::Device& d = pOwner_->GetDevice();

			delete[] vertexBuffers_;
			delete[] indexBuffers_;

			if (fontSampler_)
			{
				d.destroySampler(fontSampler_);
				fontSampler_ = vk::Sampler();
			}

			if (descPool_)
			{
				d.destroyDescriptorPool(descPool_);
				descPool_ = vk::DescriptorPool();
			}
			if (descSetLayout_)
			{
				d.destroyDescriptorSetLayout(descSetLayout_);
				descSetLayout_ = vk::DescriptorSetLayout();
			}

			fontTexture_.Destroy();

			vshader_.Destroy();
			pshader_.Destroy();

			renderPass_.Destroy();

			d.destroyPipeline(pipeline_);
			d.destroyPipelineLayout(pipelineLayout_);

			pOwner_ = nullptr;
		}
		guiHandle_ = nullptr;
	}

	//----
	// フォントイメージ生成
	bool Gui::CreateFontImage(vk::CommandBuffer& cmdBuff, Buffer& staging)
	{
		if (!pOwner_)
		{
			return false;
		}

		ImGuiIO& io = ImGui::GetIO();

		unsigned char* pixels;
		int width, height;
		io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
		size_t upload_size = width * height * 4 * sizeof(char);

		// Stagingバッファ作成
		if (!staging.InitializeAsStaging(*pOwner_, upload_size, pixels))
		{
			return false;
		}

		// イメージ作成
		if (!fontTexture_.InitializeFromStaging(*pOwner_, cmdBuff, staging, vk::Format::eR8G8B8A8Unorm, width, height))
		{
			return false;
		}

		// DescriptorSetへ登録
		{
			vk::DescriptorImageInfo texDescInfo(
				fontSampler_, fontTexture_.GetView(), vk::ImageLayout::eGeneral);

			std::array<vk::WriteDescriptorSet, 1> descSetInfos{
				vk::WriteDescriptorSet(descSet_, 0, 0, 1, vk::DescriptorType::eCombinedImageSampler, &texDescInfo, nullptr, nullptr),
			};
			pOwner_->GetDevice().updateDescriptorSets(descSetInfos, nullptr);
		}

		io.Fonts->SetTexID(fontTexture_.GetImage());

		return true;
	}

	//----
	void Gui::RenderDrawList(ImDrawData* draw_data)
	{
		ImGuiIO& io = ImGui::GetIO();

		Gui* pThis = guiHandle_;
		uint32_t frameIndex = pThis->pOwner_->GetCurrentBufferIndex();
		size_t nonCohSize = pThis->nonCoherentAtomSize_;

		// 頂点バッファ生成
		vsl::Buffer& vbuffer = pThis->vertexBuffers_[frameIndex];
		size_t vertex_size = draw_data->TotalVtxCount * sizeof(ImDrawVert);
		size_t coherent_vertex_size = ((vertex_size + nonCohSize - 1) / nonCohSize) * nonCohSize;
		if (vbuffer.GetSize() < vertex_size)
		{
			vbuffer.Destroy();
			vbuffer.InitializeAsMappableVertexBuffer(*pThis->pOwner_, coherent_vertex_size);
		}

		// インデックスバッファ生成
		vsl::Buffer& ibuffer = pThis->indexBuffers_[frameIndex];
		size_t index_size = draw_data->TotalIdxCount * sizeof(ImDrawIdx);
		size_t coherent_index_size = ((index_size + nonCohSize - 1) / nonCohSize) * nonCohSize;
		if (ibuffer.GetSize() < index_size)
		{
			ibuffer.Destroy();
			ibuffer.InitializeAsMappableIndexBuffer(*pThis->pOwner_, coherent_index_size);
		}

		// 頂点・インデックスのメモリを上書き
		{
			vk::Device& vkDev = pThis->pOwner_->GetDevice();
			ImDrawVert* vtx_dst = static_cast<ImDrawVert*>(vkDev.mapMemory(vbuffer.GetDevMem(), 0, coherent_vertex_size));
			ImDrawIdx* idx_dst = static_cast<ImDrawIdx*>(vkDev.mapMemory(ibuffer.GetDevMem(), 0, coherent_index_size));

			for (int n = 0; n < draw_data->CmdListsCount; n++)
			{
				const ImDrawList* cmd_list = draw_data->CmdLists[n];
				memcpy(vtx_dst, cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
				memcpy(idx_dst, cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
				vtx_dst += cmd_list->VtxBuffer.Size;
				idx_dst += cmd_list->IdxBuffer.Size;
			}

			std::array<vk::MappedMemoryRange, 2> ranges{
				vk::MappedMemoryRange(vbuffer.GetDevMem(), 0, coherent_vertex_size),
				vk::MappedMemoryRange(ibuffer.GetDevMem(), 0, coherent_index_size),
			};
			vkDev.flushMappedMemoryRanges(ranges);

			vkDev.unmapMemory(vbuffer.GetDevMem());
			vkDev.unmapMemory(ibuffer.GetDevMem());
		}

		// レンダーパス開始
		auto& cmdBuffer = pThis->pOwner_->GetCurrentCommandBuffer();
		cmdBuffer.beginRenderPass(pThis->passBeginInfo_, vk::SubpassContents::eInline);

		// 各種リソース等のバインド
		{
			cmdBuffer.bindDescriptorSets(vk::PipelineBindPoint::eGraphics, pThis->pipelineLayout_, 0, pThis->descSet_, nullptr);
			cmdBuffer.bindPipeline(vk::PipelineBindPoint::eGraphics, pThis->pipeline_);

			vk::DeviceSize offsets = 0;
			cmdBuffer.bindVertexBuffers(0, vbuffer.GetBuffer(), offsets);
			cmdBuffer.bindIndexBuffer(ibuffer.GetBuffer(), 0, vk::IndexType::eUint16);

			float scate_trans[4];
			scate_trans[0] = 2.0f / io.DisplaySize.x;
			scate_trans[1] = 2.0f / io.DisplaySize.y;
			scate_trans[2] = -1.0f;
			scate_trans[3] = -1.0f;
			cmdBuffer.pushConstants(pThis->pipelineLayout_, vk::ShaderStageFlagBits::eVertex, 0, sizeof(scate_trans), scate_trans);
		}

		// コマンドリストの描画
		int vtx_offset = 0;
		int idx_offset = 0;
		for (int n = 0; n < draw_data->CmdListsCount; n++)
		{
			const ImDrawList* cmd_list = draw_data->CmdLists[n];
			for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
			{
				const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
				if (pcmd->UserCallback)
				{
					pcmd->UserCallback(cmd_list, pcmd);
				}
				else
				{
					vk::Rect2D scissor(
						vk::Offset2D((int32_t)pcmd->ClipRect.x, (int32_t)pcmd->ClipRect.y),
						vk::Extent2D((uint32_t)(pcmd->ClipRect.z - pcmd->ClipRect.x), (uint32_t)(pcmd->ClipRect.w - pcmd->ClipRect.y + 1/* +1 ??? */)));
					cmdBuffer.setScissor(0, scissor);

					cmdBuffer.drawIndexed(pcmd->ElemCount, 1, idx_offset, vtx_offset, 1);
				}
				idx_offset += pcmd->ElemCount;
			}
			vtx_offset += cmd_list->VtxBuffer.Size;
		}

		cmdBuffer.endRenderPass();
	}

	//----
	// 新しいフレームの開始
	void Gui::BeginNewFrame(uint32_t frameWidth, uint32_t frameHeight, const InputData& input, float frameScale, float timeStep)
	{
		ImGuiIO& io = ImGui::GetIO();

		// フレームバッファのサイズを指定する
		io.DisplaySize = ImVec2((float)frameWidth, (float)frameHeight);
		io.DisplayFramebufferScale = ImVec2(frameScale, frameScale);

		// 時間進行を指定
		io.DeltaTime = timeStep;

		// TODO: マウスによる操作
		io.MousePos = ImVec2((float)input.GetMouseX(), (float)input.GetMouseY());
		io.MouseDown[0] = input.IsMouseButtonPressed(vsl::MouseButton::LEFT);
		io.MouseDown[1] = input.IsMouseButtonPressed(vsl::MouseButton::RIGHT);
		io.MouseDown[2] = input.IsMouseButtonPressed(vsl::MouseButton::MIDDLE);

		// 新規フレーム開始
		ImGui::NewFrame();
	}

}	// namespace vsl


//	EOF
