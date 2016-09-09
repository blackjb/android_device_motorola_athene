/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <cutils/properties.h>
#include <unistd.h>
#include <cstring>
#include <string>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

/* Target-Specific Dalvik Heap & HWUI Configuration */
void target_ram() {
    std::string ram;
    ram = property_get("ro.boot.ram");

    if (ram == "2GB") {
        property_set("dalvik.vm.heapstartsize", "16m");
        property_set("dalvik.vm.heapgrowthlimit", "192m");
        property_set("dalvik.vm.heapsize", "512m");
        property_set("dalvik.vm.heaptargetutilization", "0.75");
        property_set("dalvik.vm.heapminfree", "2m");
        property_set("dalvik.vm.heapmaxfree", "8m");

        property_set("ro.hwui.texture_cache_size", "72");
        property_set("ro.hwui.layer_cache_size", "48");
        property_set("ro.hwui.r_buffer_cache_size", "8");
        property_set("ro.hwui.path_cache_size", "32");
        property_set("ro.hwui.gradient_cache_size", "1");
        property_set("ro.hwui.drop_shadow_cache_size", "6");
        property_set("ro.hwui.texture_cache_flushrate", "0.4");
        property_set("ro.hwui.text_small_cache_width", "1024");
        property_set("ro.hwui.text_small_cache_height", "1024");
        property_set("ro.hwui.text_large_cache_width", "2048");
        property_set("ro.hwui.text_large_cache_height", "1024");
    } else if (ram == "3GB") {
        property_set("dalvik.vm.heapstartsize", "8m");
        property_set("dalvik.vm.heapgrowthlimit", "265m");
        property_set("dalvik.vm.heapsize", "512m");
        property_set("dalvik.vm.heaptargetutilization", "0.75");
        property_set("dalvik.vm.heapminfree", "512k");
        property_set("dalvik.vm.heapmaxfree", "8m");

        property_set("ro.hwui.texture_cache_size", "72");
        property_set("ro.hwui.layer_cache_size", "48");
        property_set("ro.hwui.r_buffer_cache_size", "8");
        property_set("ro.hwui.path_cache_size", "32");
        property_set("ro.hwui.gradient_cache_size", "1");
        property_set("ro.hwui.drop_shadow_cache_size", "6");
        property_set("ro.hwui.texture_cache_flushrate", "0.4");
        property_set("ro.hwui.text_small_cache_width", "1024");
        property_set("ro.hwui.text_small_cache_height", "1024");
        property_set("ro.hwui.text_large_cache_width", "2048");
        property_set("ro.hwui.text_large_cache_height", "1024");
    } else if (ram == "4GB") {
        property_set("dalvik.vm.heapstartsize", "8m");
        property_set("dalvik.vm.heapgrowthlimit", "256m");
        property_set("dalvik.vm.heapsize", "512m");
        property_set("dalvik.vm.heaptargetutilization", "0.25");
        property_set("dalvik.vm.heapminfree", "4m");
        property_set("dalvik.vm.heapmaxfree", "16m");

        property_set("ro.hwui.texture_cache_size", "72");
        property_set("ro.hwui.layer_cache_size", "48");
        property_set("ro.hwui.r_buffer_cache_size", "8");
        property_set("ro.hwui.path_cache_size", "32");
        property_set("ro.hwui.gradient_cache_size", "1");
        property_set("ro.hwui.drop_shadow_cache_size", "6");
        property_set("ro.hwui.texture_cache_flushrate", "0.4");
        property_set("ro.hwui.text_small_cache_width", "1024");
        property_set("ro.hwui.text_small_cache_height", "1024");
        property_set("ro.hwui.text_large_cache_width", "2048");
        property_set("ro.hwui.text_large_cache_height", "1024");
    }
}

void num_sims() {
    std::string dualsim;
    dualsim = property_get("ro.boot.dualsim");

    /* START FIXME: stop haxing */
    char dualsim_char[PROP_VALUE_MAX];
    std::strcpy(dualsim_char, dualsim.c_str());
    property_set("ro.hw.dualsim", dualsim_char);
    /* END FIXME: stop haxing */

    if (dualsim == "true") {
        property_set("persist.radio.multisim.config", "dsds");
	} else {
        property_set("persist.radio.multisim.config", "");    
	}
}

void vendor_load_properties()
{
    std::string device;
    std::string device_boot;
    std::string platform;
    std::string radio;
    std::string sku;
    char devicename[PROP_VALUE_MAX];

    platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
    return;

    device_boot = property_get("ro.boot.device");
    radio = property_get("ro.boot.radio");
    sku = property_get("ro.boot.hardware.sku");

    /* Common for all models */
    property_set("ro.build.product", "athene");
    property_set("ro.product.model", "Moto G (4)");
    property_set("ro.mot.build.customerid", "retail");
    property_set("persist.radio.mot_ecc_custid", "common");
    property_set("persist.radio.mot_ecc_enabled", "1");
    property_set("persist.radio.force_get_pref", "1");
    property_set("ro.telephony.default_network", "10,0");

    /* START FIXME: stop haxing */
    char device_boot_char[PROP_VALUE_MAX];
    std::strcpy(device_boot_char, device_boot.c_str());
    property_set("ro.hw.device", device_boot_char);
    
    char radio_char[PROP_VALUE_MAX];
    std::strcpy(radio_char, radio.c_str());
    property_set("ro.hw.radio", radio_char);
    /* END FIXME: stop haxing */
    
    target_ram();
    num_sims();

    if (device_boot == "athene_13mp") {
        /* Moto G4 (XT162x) */
        property_set("ro.product.device", "athene");
        property_set("ro.build.description", "athene-user 6.0.1 MPJ24.139-23.4 4 release-keys");
        property_set("ro.build.fingerprint", "motorola/athene/athene:6.0.1/MPJ24.139-23.4/4:user/release-keys");
        property_set("ro.hw.fps", "false");
    } else {
        /* Moto G4 Plus (XT164x) */
        property_set("ro.product.device", "athene_f");
        property_set("ro.build.description", "athene_f-user 6.0.1 MPJ24.139-23.4 4 release-keys");
        property_set("ro.build.fingerprint", "motorola/athene_f/athene_f:6.0.1/MPJ24.139-23.4/4:user/release-keys");
        property_set("ro.hw.fps", "true");
    }

    /* START FIXME: stop haxing */
    device = property_get("ro.product.device");
    char device_char[PROP_VALUE_MAX];
    std::strcpy(device_char, device.c_str());

    char sku_char[PROP_VALUE_MAX];
    std::strcpy(sku_char, sku.c_str());
    
    strlcpy(devicename, device_char, sizeof(devicename));
    INFO("Found sku id: %s setting build properties for %s device\n", sku_char, devicename);
    /* END FIXME: stop haxing */

}
