#include "pch.hpp"
#include <imgui-cocos.hpp>
#include <Geode/loader/SettingEvent.hpp>

$on_mod(Loaded) {
    // This starts the OpenHack logic
    openhack::initialize();

    auto *mod = geode::Mod::get();
    ImGuiCocos::get().setForceLegacy(mod->getSettingValue<bool>("legacy-render"));
    
    geode::listenForSettingChanges<bool>("legacy-render", [](bool value) {
        ImGuiCocos::get().setForceLegacy(value);
    });
}
