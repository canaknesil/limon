__precompile__()

module LimonREPL

import REPL: REPL, LineEdit


function on_enter_func(s)
    println("----- ON ENTER -----")

    str = String(take!(copy(LineEdit.buffer(s))))
    res = findfirst("end", str)
    if res == nothing
        return false
    else
        return true
    end
end


function on_done_func(str)
    println("----- ON DONE -----")
    println(str)
end


function initrepl(repl)

    text  = "limon> "
    color = Base.text_colors[:yellow]
    key   = ')'

    julia_mode = repl.interface.modes[1]

    prefix = repl.hascolor ? color : ""
    suffix = repl.hascolor ? (repl.envcolors ? Base.input_color : repl.input_color) : ""

    limon_mode = LineEdit.Prompt(text;
                                 prompt_prefix    = prefix,
                                 prompt_suffix    = suffix,
                                 repl             = repl,
                                 on_enter         = on_enter_func,
                                 complete         = REPL.REPLCompletionProvider())
    limon_mode.on_done = REPL.respond(on_done_func, repl, limon_mode)

    push!(repl.interface.modes, limon_mode)

    hp                     = julia_mode.hist
    hp.mode_mapping[:limon] = limon_mode
    limon_mode.hist         = hp

    search_prompt, skeymap = LineEdit.setup_search_keymap(hp)

    mk = REPL.mode_keymap(julia_mode)

    limon_keymap = Dict(
        key => (s, args...) ->
        if isempty(s) || position(LineEdit.buffer(s)) == 0
        buf = copy(LineEdit.buffer(s))
        LineEdit.transition(s, limon_mode) do
        LineEdit.state(s, limon_mode).input_buffer = buf
        end
        else
        LineEdit.edit_insert(s, key)
        end
    )

    limon_mode.keymap_dict = LineEdit.keymap(Dict[
        skeymap,
        mk,
        LineEdit.history_keymap,
        LineEdit.default_keymap,
        LineEdit.escape_defaults,
    ])
    julia_mode.keymap_dict = LineEdit.keymap_merge(julia_mode.keymap_dict, limon_keymap)

    nothing
end

function __init__()
    isdefined(Base, :active_repl) ? initrepl(Base.active_repl) : nothing
end

end # module
