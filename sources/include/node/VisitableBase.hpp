#ifndef NODE_XML_HPP
#define NODE_XML_HPP

#include <memory>

namespace Node
{
    namespace XML
    {
        struct Document;
        struct Element;
        struct Data;
        struct CDATA;
        struct Comment;
        struct Declaration;
        struct Doctype;
        struct ProcessingIntruction;

        struct Visitor
        {
            virtual void visit(Document * node) = 0;
            virtual void visit(Element * node) = 0;
            virtual void visit(Data * node) = 0;
            virtual void visit(CDATA * node) = 0;
            virtual void visit(Declaration * node) = 0;
            virtual void visit(Comment * node) = 0;
            virtual void visit(Doctype * node) = 0;
            virtual void visit(ProcessingIntruction * node) = 0;

            virtual ~Visitor() = default;
        };

        // the common base to allow dynamic dispatch
        struct VisitableBase
                : std::enable_shared_from_this<VisitableBase>
        {
            virtual void accept(Visitor & v) = 0;

            std::shared_ptr<VisitableBase> getptr()
            {
                return shared_from_this();
            }
        };

        struct Document : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

        struct Element : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

        struct Data : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

        struct CDATA : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

        struct Comment : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

        struct Declaration : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

        struct Doctype : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

        struct ProcessingIntruction : VisitableBase
        {
            virtual void accept(Visitor & v) {}
        };

    } // Node::XML
} // Node

#endif /*  ndef NODE_XML_HPP */
