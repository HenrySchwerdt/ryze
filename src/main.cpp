#include "core/editor/editor.hpp"
#include "core/theme/theme.hpp"
#include "core/ui/ui.hpp"
#include "core/terminal/terminal.hpp"
#include "core/screen/screen.hpp"

int main()
{
    theme::Theme theme = theme::Theme::Nightlify();
    editor::Editor* ryze = new editor::Editor(&theme);
    ryze->Run();
    ryze->~Editor();
    return 0;
}
