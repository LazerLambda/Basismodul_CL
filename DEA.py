


class DEA:

    # Aufgabe 1
    def __init__(self,
            sigma,
            q,
            s,
            f,
            delta):
        self.initial_stateigmaClass = sigma
        self.q = q
        self.initial_state = s
        self.f = f
        self.deltaClass = {(q_from, label):q_to for (q_from, label, q_to) in delta}
        
        self.current = self.initial_state

    def transition(self, q_from, label):
        if (q_from, label) in self.deltaClass:
            return self.deltaClass[(q_from, label)]
        else:
            return None

    def accepts(self, word) -> bool:

        if len(word) == 0:
            if self.current in self.f:
                return True
            else:
                self.current = self.initial_state
                return False

        head = word[0]
        tail = word[1:]
        
        transition = self.transition(self.current, head)
        if transition != None:
            self.current = transition
            result = True and self.accepts(tail)
            self.current = self.initial_state
            return result
        else:
            self.current = self.initial_state
            return False
    
    # Aufgabe 2

    @property
    def states(self):
        return self.q
    
    @property
    def final_states(self):
        return self.f

    @property
    def intitial_state(self):
        return self.initial_state

    @property
    def sigma(self):
        return self.initial_stateigmaClass

    @property
    def delta(self) -> set:
        #{key:value for (key,value) in dictonary.items()}
        return {(q_from, label, q_to) for ((q_from, label), q_to) in self.deltaClass.items()}



        

## Init for test

ex_data_01_states = set([0,1,2,3,4])
ex_data_01 = {
    "sigma" : set("abcdefghijklmnopqrstuvwxyz"),
    "q": ex_data_01_states, 
    "s" : 0,
    "F" : set([4]),
    "delta": set([
        (0,"a", 2),
        (0,"b", 1),
        (1,"a", 3),
        (3,"x", 4),
        (2,"h", 4),
        (2,"r", 3)
    ])}

test = DEA(
    ex_data_01["sigma"],
    ex_data_01["q"],
    ex_data_01["s"],
    ex_data_01["F"],
    ex_data_01["delta"],
)


## Test
assert test.transition(0, "a") == 2
assert test.transition(0, "z") == None

assert test.accepts("bax")
assert test.accepts("ah")
assert not test.accepts("ar")
assert not test.accepts("asdf")



## Draw the DEA
import graphviz

def draw_automaton(aut):

    g = graphviz.Digraph('Automaton')

    for state in aut.states:
        if state in aut.final_states:
            g.attr('node', style='bold')
        if state == aut.initial_state:
            g.node(str(state), label="-> " + str(state))
        else:
            g.node(str(state))
        g.attr('node', style='solid')

    for x, label, z in aut.delta:
        g.edge(str(x), str(z), label=" " + label + " ")

    return g

# Aufruf durch
g = draw_automaton(test)
g.render('graphviz/aut.gv', view=True)

